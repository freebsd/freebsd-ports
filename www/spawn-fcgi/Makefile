# New ports collection makefile for:		spawn-fcgi
# Date created:					17 Mar 2009
# Whom:						genserg@hotmail.com
#
# $FreeBSD$
#

PORTNAME=	spawn-fcgi
PORTVERSION=	1.6.3
CATEGORIES=	www
MASTER_SITES=	http://www.lighttpd.net/download/

MAINTAINER=	genserg@hotmail.com
COMMENT=	spawn-fcgi is used to spawn fastcgi applications

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_RC_SUBR=	spawn-fcgi

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		spawn-fcgi.1

PLIST_FILES=	bin/spawn-fcgi

.include <bsd.port.pre.mk>

SUB_LIST+=	REQUIRE="DAEMON"

.include <bsd.port.post.mk>
