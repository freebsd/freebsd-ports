# New ports collection makefile for:	mod_blosxom
# Date created:				6 April 2003
# Whom:					Gea-Suan Lin <gslin@ccca.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	mod_blosxom
PORTVERSION=	0.05
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	mod-blosxom

MAINTAINER=	gslin@ccca.nctu.edu.tw
COMMENT=	Apache module to build the extremely lightweight Weblog environment

APXS?=		${LOCALBASE}/sbin/apxs
APACHE_PORT?=	${PORTSDIR}/www/apache13

BUILD_DEPENDS=	${APXS}:${APACHE_PORT}
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_REINPLACE=	yes

post-patch:
	${REINPLACE_CMD} -e 's,^APXS=.*,APXS=${APXS},' ${WRKSRC}/Makefile

.include <bsd.port.mk>
