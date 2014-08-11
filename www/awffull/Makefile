# Created by: Chadwick Sorrell chad@wickdev.com
# $FreeBSD$

PORTNAME=	awffull
PORTVERSION=	3.10.2
PORTREVISION=	11
CATEGORIES?=	www
MASTER_SITES=	http://www.stedee.id.au/files/

MAINTAINER?=	chad@wickdev.com
COMMENT=	AWFFull is a webserver log analysis tool forked from Webalizer

LICENSE=	GPLv3

BUILD_DEPENDS=	${LOCALBASE}/lib/X11/fonts/bitstream-vera/Vera.ttf:${PORTSDIR}/x11-fonts/bitstream-vera
LIB_DEPENDS=	libgd.so:${PORTSDIR}/graphics/gd \
		libpng15.so:${PORTSDIR}/graphics/png \
		libpcre.so:${PORTSDIR}/devel/pcre
RUN_DEPENDS:=	${BUILD_DEPENDS}

CONFLICTS?=	ja-awffull-[0-9]*

FONTDEFAULT?=	${LOCALBASE}/lib/X11/fonts/bitstream-vera/VeraBd.ttf
FONTLABEL?=	${LOCALBASE}/lib/X11/fonts/bitstream-vera/Vera.ttf

OPTIONS_DEFINE=	GEOIP DOCS EXAMPLES NLS
OPTIONS_SUB=	yes

USES=		gettext iconv

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-font-default=${FONTDEFAULT} \
		--with-font-label=${FONTLABEL} \
		--with-etcdir=${PREFIX}/etc

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GEOIP_LIB_DEPENDS=	libGeoIP.so:${PORTSDIR}/net/GeoIP
GEOIP_CONFIGURE_ENABLE=	geoip

NLS_CONFIGURE_ENABLE=	nls

PORTDOCS=	*
PORTEXAMPLES=	*

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} \
		COPYING ChangeLog DNS.README PERFORMANCE_TIPS.txt \
		README* TODO country-codes.txt \
		${STAGEDIR}${DOCSDIR})
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/sample* ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/*.pl ${STAGEDIR}${EXAMPLESDIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/flags
	${INSTALL_DATA} ${WRKSRC}/flags/README ${WRKSRC}/flags/*.png \
		${STAGEDIR}${EXAMPLESDIR}/flags

.include <bsd.port.mk>
