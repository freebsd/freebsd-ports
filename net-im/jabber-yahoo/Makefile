# New ports collection makefile for:	jabber-yahoo
# Date created:			12 Oct 2002
# Whom:				Nick Sayer <nsayer@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	yahoo
PORTVERSION=	2.3.2
CATEGORIES=	net
MASTER_SITES=	http://www.jabberstudio.org/files/yahoo-transport-2/
PKGNAMEPREFIX=	jabber-
DISTNAME=	yahoo-transport-${PORTVERSION}
DIST_SUBDIR=	jabber

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Jabber Yahoo Transport module

BUILD_DEPENDS=	${LOCALBASE}/sbin/jabberd:${PORTSDIR}/net/jabber

USE_GNOME=	glib12
USE_GMAKE=	yes
USE_ICONV=	yes

WRKSRC=		${WRKDIR}/yahoo-transport-${PORTVERSION}
PLIST_FILES=	lib/jabber/yahoo-transport.so etc/yahoo-jabber.xml.sample

do-install:
	${INSTALL_DATA} ${WRKSRC}/yahoo-transport.so ${PREFIX}/lib/jabber/
	${INSTALL_DATA} ${WRKSRC}/yahoo-jabber.xml ${PREFIX}/etc/yahoo-jabber.xml.sample

.include <bsd.port.mk>
