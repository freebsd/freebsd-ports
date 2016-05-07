# $FreeBSD$

PORTNAME=	gpx2map
PORTVERSION=	0.1
CATEGORIES=	www

MAINTAINER=	koue@chaosophia.net
COMMENT=	Put GPX track on Google Map or OpenStreetMap

LICENSE=	GPLv3

RUN_DEPENDS=	p5-XML-Twig>=0:textproc/p5-XML-Twig \
		p5-Template-Toolkit>=0:www/p5-Template-Toolkit \
		p5-Geo-Distance>=0:math/p5-Geo-Distance

USE_GITHUB=	yes
GH_ACCOUNT=	sd2k9

USES=		shebangfix perl5
SHEBANG_FILES=	gpx2map
NO_BUILD=	yes
DATADIR=	${PREFIX}/share/${PORTNAME}

PLIST_FILES=	bin/gpx2map \
		share/gpx2map/gpx2map.google.template \
		share/gpx2map/gpx2map.osm.template

OPTIONS_DEFINE=	GNUPLOT

GNUPLOT_DESC=	Enable draw track profiles
GNUPLOT_RUN_DEPENDS=	p5-Chart-Gnuplot>=0:graphics/p5-Chart-Gnuplot

post-patch:
	@${REINPLACE_CMD} -e "s|gpx2map.google.template|${DATADIR}/gpx2map.google.template|" \
		-e "s|gpx2map.osm.template|${DATADIR}/gpx2map.osm.template|" \
		-e "s|.FindBin::RealBin/.opts{'map_template_google'}|${DATADIR}/gpx2map.google.template|" \
		-e "s|.FindBin::RealBin/.opts{'map_template_osm'}|${DATADIR}/gpx2map.osm.template|" \
		${WRKSRC}/gpx2map

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/gpx2map ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/gpx2map.google.template ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/gpx2map.osm.template ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
