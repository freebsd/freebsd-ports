# New ports collection makefile for:	jabber-yahoo
# Date created:			12 Oct 2002
# Whom:				Nick Sayer <nsayer@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	yahoo
PORTVERSION=	2.1
CATEGORIES=	net
MASTER_SITES=	http://yahoo-transport-2.jabberstudio.org/
PKGNAMEPREFIX=	jabber-
DISTNAME=	yahoo-t-${PORTVERSION}
DIST_SUBDIR=	jabber

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	Jabber Yahoo Transport module

BUILD_DEPENDS=	${LOCALBASE}/sbin/jabberd:${PORTSDIR}/net/jabber
LIB_DEPENDS=	iconv.3:${PORTSDIR}/converters/libiconv

USE_GLIB=	yes
USE_GMAKE=	yes

WRKSRC=		${WRKDIR}/yahoo-transport-2

do-install:
	${INSTALL_DATA} ${WRKSRC}/yahoo-transport.so ${PREFIX}/lib/jabber/
	${INSTALL_DATA} ${WRKSRC}/yahoo-jabber.xml ${PREFIX}/etc/yahoo-jabber.xml.sample

.include <bsd.port.mk>
