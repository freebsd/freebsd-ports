PORTNAME=	mod_qos
DISTVERSION=	11.72
CATEGORIES=	www
MASTER_SITES=	SF/mod-qos
DIST_SUBDIR=	apache2

MAINTAINER=	fax@nohik.ee
COMMENT=	QoS for Apache

LICENSE=	APACHE20

LIB_DEPENDS=	libpcre.so:devel/pcre

USES=		apache:2.2+

AP_FAST_BUILD=	yes
AP_GENPLIST=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/apache2

.include <bsd.port.mk>
