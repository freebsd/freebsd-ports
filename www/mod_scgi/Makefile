# Created by: Neil Blakey-Milner <nbm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mod_scgi
PORTVERSION=	1.14
CATEGORIES=	www
MASTER_SITES=	http://python.ca/scgi/releases/
DISTNAME=	scgi-${PORTVERSION:S/.a/a/}

MAINTAINER=	w.schwarzenfeld@aon.at
COMMENT=	Apache module that implements the client side of the SCGI protocol

LICENSE=	MIT
LICENSE_FILE=	${WRKDIR}/${DISTNAME}/LICENSE.txt

SCGI_DIR=	apache2
WRKSRC=		${WRKDIR}/${DISTNAME}/${SCGI_DIR}

USE_APACHE=	22+
AP_FAST_BUILD=	yes
AP_GENPLIST=	yes

.include <bsd.port.pre.mk>

.if ${APACHE_VERSION} == 24
EXTRA_PATCHES=	${FILESDIR}/apache24-compat-mod__scgi.c
.endif

.include <bsd.port.post.mk>
