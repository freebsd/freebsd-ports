# New ports collection makefile for:	jabber-jud
# Date created:			14 Apr 2002
# Whom:				Sean Chittenden <seanc@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	jud
PORTVERSION=	0.4
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://download.jabber.org/dists/1.4/final/
PKGNAMEPREFIX=	jabber-
DIST_SUBDIR=	jabber

MAINTAINER=	seanc@FreeBSD.org
COMMENT=	Jabber User Directory module

BUILD_DEPENDS=	${LOCALBASE}/sbin/jabberd:${PORTSDIR}/net/jabber

USE_GMAKE=	yes

post-patch:
	@echo "${PREFIX}" > ${WRKSRC}/.prefix-freebsd

do-install:
	${INSTALL_DATA} ${WRKSRC}/jud.so ${PREFIX}/lib/jabber/

post-install:
	@cat pkg-message

.include <bsd.port.mk>
