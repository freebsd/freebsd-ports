# New ports collection makefile for:	Jabber MSN Transport
# Date created:				Sat May 04 06:00:02 PDT 2002
# Whom:					Martijn Lina <martijn@pacno.net>
#
# $FreeBSD$

PORTNAME=	msn
PORTVERSION=	1.3
CATEGORIES=	net
MASTER_SITES=	http://msn-transport.jabberstudio.org/
PKGNAMEPREFIX=	jabber-
PKGNAMESUFFIX=	-transport
DISTNAME=	msn-transport-1.3-cvs3
DIST_SUBDIR=	jabber

MAINTAINER=	martijn@pacno.net
COMMENT=	Jabber MSN-Transport module

LIB_DEPENDS=	curl.3:${PORTSDIR}/ftp/curl
BUILD_DEPENDS=	${LOCALBASE}/sbin/jabberd:${PORTSDIR}/net/jabber

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+= --with-jabberd=${PREFIX}/include/jabber \
		--with-pth=${LOCALBASE}/include/pth
CONFIGURE_ENV=  LDFLAGS=-L${LOCALBASE}/lib

PORTDOCS=	README

do-install:
	${INSTALL_DATA} ${WRKSRC}/src/msntrans.so ${PREFIX}/lib/jabber/
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
