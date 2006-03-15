# New ports collection makefile for: scgi
# Date created:		19 Aug 2002
# Whom:			Neil Blakey-Milner <nbm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	scgi
PORTVERSION=	1.10
CATEGORIES=	www
MASTER_SITES=	http://www.mems-exchange.org/software/files/scgi/ \
		http://dryice.name/computer/FreeBSD/distfiles/
PKGNAMEPREFIX=	mod_
DISTNAME=	scgi-${PORTVERSION:S/.a/a/}

MAINTAINER=	dryice@dryice.name
COMMENT=	Apache module that implements the client side of the SCGI protocol

USE_APACHE=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/${SCGI_DIR}

.include <bsd.port.pre.mk>
.if exists(${LOCALBASE}/include/apache2/apr.h)
WITH_APACHE2=	yes
.endif

.if defined(WITH_APACHE2)
SCGI_DIR=	apache2
PLIST_SUB=	APACHE_DIR=apache2
.else
SCGI_DIR=	apache1
PLIST_SUB=	APACHE_DIR=apache
.endif

do-build:
	cd ${WRKSRC} && ${APXS} -c mod_scgi.c
do-install:
	cd ${WRKSRC} && ${APXS} -i -c mod_scgi.c

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
