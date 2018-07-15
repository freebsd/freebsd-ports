# $FreeBSD$

PORTNAME=	zygrib
DISTVERSION=	8.0.1
CATEGORIES=	misc
MASTER_SITES=	http://www.zygrib.org/getfile.php?file=
DISTNAME=	zyGrib-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Weather data visualization, GRIB file viewer

LICENSE=	GPLv3

BROKEN_i386=	g2clib/libg2c.a: could not read symbols: File format not recognized

FETCH_DEPENDS=	curl:ftp/curl
LIB_DEPENDS=	libjasper.so:graphics/jasper \
		libnova.so:astro/libnova \
		libpng16.so:graphics/png \
		libproj.so:graphics/proj \
		libqwt6.so:x11-toolkits/qwt6@qt5

USES=		gmake localbase tar:tgz qt:5
USE_QT=		core gui network printsupport widgets xml buildtools_build qmake_build
USE_GL=		gl

WRKSRC=		${WRKDIR}/zyGrib-${DISTVERSION}
CXXFLAGS+=	-I${LOCALBASE}/include/qt5/qwt6
BINARY_ALIAS=	make=gmake gcc=cc

local-makesum: # Workaround: the generic 'make makesum' is broken when custom do-fetch is defined: it calls ${SCRIPTSDIR}/do-fetch.sh.
	@${MAKE} distclean fetch makesum

do-fetch: # fetch needs cookies
	@if [ "${FORCE_FETCH_ALL}" = "true" ] || ! [ -f "${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}" ]; then \
		${LOCALBASE}/bin/curl -fLC - \
			--cookie nada -o /dev/null "${MASTER_SITES}${DISTNAME}${EXTRACT_SUFX}" \
			--next \
			--cookie nada --retry-delay 3 -o "${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}" "${MASTER_SITES}${DISTNAME}${EXTRACT_SUFX}"; \
	fi

post-extract: # unbundle qwt
	@${RM} -r ${WRKSRC}/src/qwt-6.1.3

post-patch:
	@${FIND} ${WRKSRC} -name Makefile | ${XARGS} ${REINPLACE_CMD} -e 's|/usr/bin/qmake|${QMAKE}|'
	@${REINPLACE_CMD} -E ' \
		s,return pathData\(\)\+"data/(colors|fonts|gis|maps/gshhs|stuff|img)/",return QString()+"${DATADIR}/\1/", ; \
		s,pathData\(\)\+"data/tr/zyGrib_",QString()+"${PREFIX}/share/locale/tr/LC_MESSAGES/zyGrib_",' \
		${WRKSRC}/src/util/Util.h

post-install:
	@${RM} ${STAGEDIR}${PREFIX}/zyGrib
	${INSTALL_PROGRAM} ${WRKSRC}/src/zyGrib ${STAGEDIR}${PREFIX}/bin
	@${MV} ${STAGEDIR}${DATADIR}/tr/* ${STAGEDIR}${PREFIX}/share/locale/tr/LC_MESSAGES/
	@cd ${STAGEDIR}${DATADIR} && ${RMDIR} tr config grib

.include <bsd.port.mk>
