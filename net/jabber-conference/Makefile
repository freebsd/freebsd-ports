# New ports collection makefile for:	jabber-conference
# Date created:			15 Apr 2002
# Whom:				Sean Chittenden <seanc@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	conference
PORTVERSION=	0.4.1
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://download.jabber.org/dists/1.4/final/old/
PKGNAMEPREFIX=	jabber-
DIST_SUBDIR=	jabber

MAINTAINER=	seanc@FreeBSD.org
COMMENT=	Jabber Conferencing module

BUILD_DEPENDS=	${LOCALBASE}/sbin/jabberd:${PORTSDIR}/net/jabber

PLIST_FILES=	lib/jabber/conference.so
USE_GMAKE=	yes

CONFIGURE_ARGS+=	--with-jabberd=${PREFIX}/include/jabber

post-patch:
	@echo "${PREFIX}" > ${WRKSRC}/.prefix-freebsd

do-install:
	${INSTALL_DATA} ${WRKSRC}/conference.so ${PREFIX}/lib/jabber/

post-install:
	@cat pkg-message

.include <bsd.port.mk>
