# New ports collection makefile for:	USA zipcodes
# Date created:         1997-12-30
# Whom:                 wosch
#
# $FreeBSD$
#

PORTNAME=	zipcodes
PORTVERSION=	1.0
CATEGORIES=	misc
MASTER_SITES=	http://galileo.spaceports.com/~jharris/distfiles/
PKGNAMEPREFIX=	us-
DISTFILES=	${PORTNAME}.gz

MAINTAINER=	jharris@widomaker.com

NO_WRKSUBDIR=	yes
EXTRACT_CMD=	${GZCAT}
EXTRACT_BEFORE_ARGS=	# None
EXTRACT_AFTER_ARGS=	> ${WRKSRC}/zipcodes
NO_BUILD=	yes

do-install:
	${INSTALL_DATA} ${WRKSRC}/zipcodes ${PREFIX}/share/misc/us.zipcodes

.include <bsd.port.mk>
