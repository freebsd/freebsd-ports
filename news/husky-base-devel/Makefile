# New ports collection makefile for:	husky-base-devel
# Date created:				2005-10-26
# Whom:					Oleg Sharoiko <os@rsu.ru>
#
# $FreeBSD$
#

PORTNAME=	base
PORTVERSION=	1.4
PORTREVISION=	1
CATEGORIES=	news mail
MASTER_SITES=	SF/husky/huskybase/1.4%20RC4
DISTNAME=	huskybase-${PORTVERSION}
EXTRACT_SUFX=	-tar.gz

MAINTAINER=	os@rsu.ru
COMMENT=	Common files for Husky Fidosoft Project. Development version

CONFLICTS=	husky-base-[0-9]*

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
.include "${.CURDIR}/../../news/husky-base-devel/Makefile.inc"
.include <bsd.port.post.mk>
