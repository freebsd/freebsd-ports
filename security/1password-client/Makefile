# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	1password-client
PORTVERSION=	0.1
CATEGORIES=	security
MASTER_SITES=	https://cache.agilebits.com/dist/1P/op/pkg/v${PORTVERSION}/

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	1Password CLI client

ONLY_FOR_ARCHS=	amd64 arm i386

USES=		zip
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/op
CONFLICTS_INSTALL=	security/op

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/op ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.pre.mk>

.if   ${ARCH} == "amd64"
DISTNAME=	op_freebsd_amd64_v${PORTVERSION}
.elif ${ARCH} == "aarch64"
DISTNAME=	op_freebsd_arm_v${PORTVERSION}
.elif ${ARCH} == "i386"
DISTNAME=	op_freebsd_386_v${PORTVERSION}
.endif

.if ${.TARGETS} == "makesum"
DISTFILES=	op_freebsd_amd64_v${PORTVERSION}${EXTRACT_SUFX} \
		op_freebsd_arm_v${PORTVERSION}${EXTRACT_SUFX} \
		op_freebsd_386_v${PORTVERSION}${EXTRACT_SUFX}
.endif

.include <bsd.port.post.mk>
