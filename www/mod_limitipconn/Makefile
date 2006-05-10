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
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
.if defined(WITH_CONNECTION_COUNT_FIX)
LMODOVERWRITE=	contrib/sbarta/mod_limitipconn.c
DISTFILES+=	${LMODOVERWRITE}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
.endif

MAINTAINER=	ychsiao@ychsiao.org
COMMENT=	Limit the number of simultaneous connections from a single client IP address

PLIST_FILES=	libexec/apache/mod_limitipconn.so
USE_APACHE=	yes
USE_REINPLACE=	yes

.if defined(WITH_CONNECTION_COUNT_FIX)
pre-patch:
	${CP} ${DISTDIR}/${LMODOVERWRITE} ${WRKSRC}
.endif

post-patch:
	${REINPLACE_CMD} -e 's,^APXS = .*,APXS = ${APXS},' ${WRKSRC}/Makefile

.include <bsd.port.mk>
