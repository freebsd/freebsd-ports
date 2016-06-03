# Created by: Chadwick Sorrell chad@wickdev.com
# $FreeBSD$

PORTNAME=	awffull
PORTVERSION=	3.10.2
PORTREVISION=	14
CATEGORIES?=	www
MASTER_SITES=	http://www.stedee.id.au/files/

MAINTAINER?=	ports@FreeBSD.org
COMMENT=	AWFFull is a webserver log analysis tool forked from Webalizer

BROKEN=		unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2016-07-04

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/share/fonts/bitstream-vera/Vera.ttf:x11-fonts/bitstream-vera
LIB_DEPENDS=	libgd.so:graphics/gd \
		libpng.so:graphics/png \
		libpcre.so:devel/pcre
RUN_DEPENDS:=	${BUILD_DEPENDS}

CONFLICTS?=	ja-awffull-[0-9]*

FONTDEFAULT?=	${LOCALBASE}/share/fonts/bitstream-vera/VeraBd.ttf
FONTLABEL?=	${LOCALBASE}/share/fonts/bitstream-vera/Vera.ttf

OPTIONS_DEFINE=	GEOIP DOCS EXAMPLES NLS
OPTIONS_SUB=	yes

USES=		gettext iconv shebangfix
SHEBANG_FILES=	contrib/awffull_history_regen.pl \
		contrib/awffull_history_regen_german.pl

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-font-default=${FONTDEFAULT} \
		--with-font-label=${FONTLABEL} \
		--with-etcdir=${PREFIX}/etc

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GEOIP_LIB_DEPENDS=	libGeoIP.so:net/GeoIP
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
