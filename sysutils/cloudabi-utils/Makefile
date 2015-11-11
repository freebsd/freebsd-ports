# Created by: Ed Schouten <ed@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cloudabi-utils
PORTVERSION=	0.6
CATEGORIES=	sysutils
MASTER_SITES=	https://nuxi.nl/distfiles/cloudabi-utils/

MAINTAINER=	ed@FreeBSD.org
COMMENT=	Utilities for running CloudABI programs

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libyaml.so:${PORTSDIR}/textproc/libyaml

ONLY_FOR_ARCHS=	aarch64 amd64
ONLY_FOR_ARCHS_REASON=	CloudABI has not yet been ported to other architectures

USES=		compiler:c11 tar:xz

PLIST_FILES=	bin/cloudabi-run \
		libexec/cloudabi-reexec \
		man/man1/cloudabi-run.1.gz

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

do-build:
	@cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} \
		PREFIX=${PREFIX} \
		${SH} build

do-install:
	@cd ${WRKSRC} && \
		ARCH=${ARCH:S/amd64/x86_64/} \
		DESTDIR=${STAGEDIR} \
		PREFIX=${PREFIX} \
		${SH} install

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 1000100
IGNORE=		CloudABI will never support this version of FreeBSD
.endif

.include <bsd.port.post.mk>
