PORTNAME=	mod_tidy
PORTVERSION=	0.5.5
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://mod-tidy.sourceforge.net/src/
DIST_SUBDIR=	apache2

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Validates the HTML output of your apache2 web server
WWW=		https://mod-tidy.sourceforge.net/

DEPRECATED=	Last upstream release was in 2005
EXPIRATION_DATE=2024-04-24

LICENSE=	APACHE20 MIT
LICENSE_COMB=	multi

LIB_DEPENDS=	libtidy5.so:www/tidy-html5

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/src
USES=		apache
AP_FAST_BUILD=	yes
AP_GENPLIST=	yes
AP_INC+=	${LOCALBASE}/include
AP_LIB+=	${LOCALBASE}/lib -ltidy5

post-patch:
	@${REINPLACE_CMD} -e "s/buffio.h/tidybuffio.h/g" \
		${WRKSRC}/mod_tidy.c

.include <bsd.port.mk>
