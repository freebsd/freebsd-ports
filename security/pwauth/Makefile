# New ports collection makefile for:	pwauth
# Date created:				Oct 14 2004
# Whom:					clement
#
# $FreeBSD$
#

PORTNAME=	pwauth
PORTVERSION=	2.2.8
CATEGORIES=	security www
MASTER_SITES=	http://www.unixpapa.com/software/

MAINTAINER=	clement@FreeBSD.org
COMMENT=	A Unix Web Authenticator

USE_REINPLACE=	yes
PLIST_FILES=	bin/pwauth

.include <bsd.port.pre.mk>

WWWUID!=	${ID} -u ${WWWOWN}

post-patch:
	@${REINPLACE_CMD} "s/%%UIDS%%/${WWWUID}/ ; \
		s/%%MINUID%%/1000/" ${WRKSRC}/config.h

do-install:
	-@${MKDIR} -p ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/pwauth ${PREFIX}/bin
	@${CHMOD} u=rxs ${PREFIX}/bin/pwauth

.include <bsd.port.post.mk>
