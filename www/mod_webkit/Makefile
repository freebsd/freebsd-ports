# New ports collection makefile for:	mod_webkit
# Date created:		2005-12-22
# Whom:			Choe, Cheng-Dae
#
# $FreeBSD$
#

PORTNAME=	mod_webkit
PORTVERSION=	0.9.2
CATEGORIES=	www
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	whitekid@gmail.com
COMMENT=	A apache module for WebWare WebKit AppServer

PATCH_DEPENDS=	${NONEXISTENT}:${WEBWARE_PORT}:extract

USE_APACHE=	1.3

WEBWARE_PORT=	${PORTSDIR}/www/py-webware
WRKSRC=		${WRKDIR}/../../../www/py-webware/work/Webware-${PORTVERSION}/WebKit/Adapters/${PORTNAME}

PLIST_FILES=	libexec/apache/mod_webkit.so

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/sbin/apxs|${APXS}|' ${WRKSRC}/Makefile

.include <bsd.port.mk>
