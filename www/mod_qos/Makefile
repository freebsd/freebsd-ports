PORTNAME=	mod_qos
DISTVERSION=	11.75
CATEGORIES=	www
MASTER_SITES=	SF/mod-qos
DIST_SUBDIR=	apache2

MAINTAINER=	fax@nohik.ee
COMMENT=	QoS for Apache
WWW=		https://mod-qos.sourceforge.net/

LICENSE=	APACHE20

LIB_DEPENDS=	libpcre2-8.so:devel/pcre2

USES=		apache

AP_FAST_BUILD=	yes
AP_GENPLIST=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/apache2

.include <bsd.port.mk>
