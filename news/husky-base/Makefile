# New ports collection makefile for:    husky-base
# Date created:                         6 January 2003
# Whom:                                 Max Khon
#
# $FreeBSD$
#

PORTNAME=	base
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	news mail
DISTNAME=	huskybase-${PORTVERSION}-src

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	Common files for Husky Fidosoft Project

WRKSRC=		${WRKDIR}/huskybse
NO_BUILD=	yes

pre-install:
	@ ${SETENV} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGDIR}/pkg-install ${PORTNAME} PRE-INSTALL

do-install:
	@${MKDIR} ${PREFIX}/etc/fido ${PREFIX}/share/doc/husky
	@${CHOWN} fido:fido ${PREFIX}/etc/fido
	@${INSTALL_DATA} ${WRKSRC}/huskymak.cfg ${PREFIX}/etc/fido

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/news/husky-base/Makefile.inc"
.include <bsd.port.post.mk>
