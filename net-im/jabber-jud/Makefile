# New ports collection makefile for:	jabber-jud
# Date created:			14 Apr 2002
# Whom:				Sean Chittenden <seanc@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	jud
PORTVERSION=	0.5
CATEGORIES=	net-im
MASTER_SITES=	http://jud.jabberstudio.org/ \
		http://freebsd.unixfreunde.de/sources/
PKGNAMEPREFIX=	jabber-
DIST_SUBDIR=	jabber

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Jabber User Directory module

BUILD_DEPENDS=	${LOCALBASE}/sbin/jabberd:${PORTSDIR}/net-im/jabber

WRKSRC=		${WRKDIR}/${PORTNAME}-ansi-c

PLIST_FILES=	lib/jabber/jud.so
USE_GMAKE=	yes

post-patch:
	@echo "${PREFIX}" > ${WRKSRC}/.prefix-freebsd

do-install:
	${INSTALL_DATA} ${WRKSRC}/jud.so ${PREFIX}/lib/jabber/

post-install:
	@cat pkg-message

.include <bsd.port.mk>
