# New ports collection makefile for:	mod_limitipconn
# Date created:				18 April 2003
# Whom:					Gea-Suan Lin <gslin@ccca.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	mod_limitipconn
PORTVERSION=	0.04
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://dominia.org/djao/limit/

MAINTAINER=	gslin@ccca.nctu.edu.tw
COMMENT=	Limit the number of simultaneous connections from a single client IP address

PLIST_FILES=	libexec/apache/mod_limitipconn.so
USE_APACHE=	yes
USE_REINPLACE=	yes

post-patch:
	${REINPLACE_CMD} -e 's,^APXS = .*,APXS = ${APXS},' ${WRKSRC}/Makefile

.include <bsd.port.mk>
