# New ports collection makefile for:	mod_rpaf
# Date created:				Mar 17, 2003
# Whom:					Clement Laforet <clement@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mod_rpaf
PORTVERSION=	0.5
CATEGORIES=	www
MASTER_SITES=	http://stderr.net/apache/rpaf/download/

MAINTAINER=	clement@FreeBSD.org
COMMENT=	Make proxied requests appear with client IP

USE_APACHE=	yes

.if defined(WITH_APACHE2)
PLIST_SUB+=	APACHE=apache2
AP_EXT=		la
SRC_FILE=	mod_rpaf-2.0.c
PKGNAMESUFFIX=	-ap2
.else
PLIST_SUB+=	APACHE=apache
AP_EXT=		so
SRC_FILE=	mod_rpaf.c
.endif

do-build:
	@cd ${WRKSRC} && ${APXS} -c -o ${PORTNAME}.${AP_EXT} ${SRC_FILE}

do-install:
	${APXS} -i -a -n ${PORTNAME:S/mod_//} ${WRKSRC}/${PORTNAME}.${AP_EXT}

.include <bsd.port.mk>
