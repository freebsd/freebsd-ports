# New ports collection makefile for:	pwauth
# Date created:				Oct 14 2004
# Whom:					clement
#
# $FreeBSD$
#

PORTNAME=	pwauth
PORTVERSION=	2.3.1
CATEGORIES=	security www
MASTER_SITES=	http://www.unixpapa.com/software/

MAINTAINER=	clement@FreeBSD.org
COMMENT=	A Unix Web Authenticator

PLIST_FILES=	bin/pwauth bin/checkfaillog

ALL_TARGET=	pwauth checkfaillog
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" LIB="-lcrypt -lpam"

.include <bsd.port.pre.mk>

WWWUID!=	${ID} -u ${WWWOWN}

post-patch:
	@${REINPLACE_CMD} "s/%%UIDS%%/${WWWUID}/ ; \
		s/%%MINUID%%/1000/" ${WRKSRC}/config.h

do-install:
	-@${MKDIR} -p ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/pwauth ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/checkfaillog ${PREFIX}/bin
	@${CHMOD} u=rxs ${PREFIX}/bin/pwauth

.include <bsd.port.post.mk>
