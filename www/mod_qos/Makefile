# Created by: Andrea Cervesato <andrea@cervesato.it>
# $FreeBSD$

PORTNAME=	mod_qos
PORTVERSION=	10.15
CATEGORIES=	www
MASTER_SITES=	SF
MASTER_SITE_SUBDIR= mod-qos
DIST_SUBDIR=	apache2

MAINTAINER=	andrea@cervesato.it
COMMENT=	Qos for Apache


USE_APACHE=	22+
AP_GENPLIST=	yes
AP_FAST_BUILD=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/apache2

NO_STAGE=	yes
.include <bsd.port.mk>
