# New ports collection makefile for: scgi
# Date created:		19 Aug 2002
# Whom:			Neil Blakey-Milner <nbm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	scgi
PORTVERSION=	1.2.a2
CATEGORIES=	www
MASTER_SITES=	http://www.mems-exchange.org/software/files/scgi/
PKGNAMEPREFIX=	mod_
DISTNAME=	scgi-${PORTVERSION:S/.a/a/}

MAINTAINER=	dryice@liu.com.cn
COMMENT=	Apache module that implements the client side of the SCGI protocol

USE_APACHE=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/${APACHE_DIR}

BROKEN=		"Does not build"

.include <bsd.port.pre.mk>
.if exists(${LOCALBASE}/include/apache2/apr.h)
WITH_APACHE2=	yes
.endif

.if defined(WITH_APACHE2)
APACHE_DIR=	apache2
PLIST_SUB=	APACHE_DIR=apache2
.else
APACHE_DIR=	apache1
PLIST_SUB=	APACHE_DIR=apache
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
