# New ports collection makefile for: scgi
# Date created:		19 Aug 2002
# Whom:			Neil Blakey-Milner <nbm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	scgi
PORTVERSION=	1.12
CATEGORIES=	www
MASTER_SITES=	http://quixote.python.ca/releases/ \
		http://dryice.name/computer/FreeBSD/distfiles/
PKGNAMEPREFIX=	${APACHE_PKGNAMEPREFIX}mod_
DISTNAME=	scgi-${PORTVERSION:S/.a/a/}

MAINTAINER=	dryice@dryice.name
COMMENT=	Apache module that implements the client side of the SCGI protocol

MAKE_JOBS_SAFE=  yes

USE_APACHE=	1.3+
WRKSRC=		${WRKDIR}/${DISTNAME}/${SCGI_DIR}

.include <bsd.port.pre.mk>

.if ${APACHE_VERSION} >= 20
SCGI_DIR=	apache2
.else
SCGI_DIR=	apache1
.endif
PLIST_SUB=	APACHE_DIR=${APACHEMODDIR}

do-build:
	cd ${WRKSRC} && ${APXS} -c mod_scgi.c
do-install:
	cd ${WRKSRC} && ${APXS} -i -c mod_scgi.c

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
