# Created by: Ed Schouten <ed@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cloudabi-utils
PORTVERSION=	0.2
CATEGORIES=	sysutils
MASTER_SITES=	https://nuxi.nl/distfiles/cloudabi-utils/

MAINTAINER=	ed@FreeBSD.org
COMMENT=	Utilities for running CloudABI programs

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS=	cloudabi-toolchain>=0:${PORTSDIR}/devel/cloudabi-toolchain
LIB_DEPENDS=	libyaml.so:${PORTSDIR}/textproc/libyaml

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	CloudABI has not yet been ported to other architectures

USES=		compiler:c11 tar:xz

PLIST_FILES=	bin/cloudabi-run \
		libexec/cloudabi-reexec \
		man/man1/cloudabi-run.1.gz

do-build:
	@cd ${WRKSRC} && \
		PREFIX=${LOCALBASE} \
		CLOUDABI_CC=${LOCALBASE}/bin/x86_64-unknown-cloudabi-cc \
		${SH} build

do-install:
	@cd ${WRKSRC} && \
		PREFIX=${STAGEDIR}${PREFIX} \
		${SH} install

.include <bsd.port.mk>
