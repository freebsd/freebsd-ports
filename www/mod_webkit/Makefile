# New ports collection makefile for:	mod_webkit
# Date created:		2005-12-22
# Whom:			Choe, Cheng-Dae
#
# $FreeBSD$
#

PORTNAME=	mod_webkit
PORTVERSION=	0.9.4
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	webware
DISTNAME=	Webware-${PORTVERSION}

MAINTAINER=	apache@FreeBSD.org
COMMENT=	A apache module for WebWare WebKit AppServer

USE_APACHE=	1.3+
AP_FAST_BUILD=	yes
AP_GENPLIST=	yes

.include <bsd.port.pre.mk>

.if ${APACHE_VERSION} >= 20
PKGNAMESUFFIX=	-ap2
APACHE_VER=	2
.else
APACHE_VER=	1
.endif

WRKSRC=		${WRKDIR}/Webware-${PORTVERSION}/WebKit/Adapters/${PORTNAME}${APACHE_VER}

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/sbin/apxs|${APXS}|' ${WRKSRC}/Makefile

.include <bsd.port.post.mk>
