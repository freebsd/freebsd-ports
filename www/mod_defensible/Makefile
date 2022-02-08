# Created by: Peter Libassi <peter@libassi.se>

PORTNAME=	mod_defensible
DISTVERSIONPREFIX=	v
DISTVERSION=	1.5
CATEGORIES=	www

MAINTAINER=	peter@libassi.se
COMMENT=	Apache 2.4 module aiming to block IP listed in DNSBL

LICENSE=	APACHE20

USES=		apache:2.4+

USE_GITHUB=	yes
GH_ACCOUNT=	jd

AP_FAST_BUILD=	yes
AP_GENPLIST=	yes
SHORTMODNAME=	defensible

SRC_FILE=	mod_defensible.c

post-patch:
	${REINPLACE_CMD} 's,%%PORTVERSION%%,${PORTVERSION},' \
		${WRKSRC}/mod_defensible.c

.include <bsd.port.mk>
