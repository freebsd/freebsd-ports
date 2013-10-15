# Created by: Lars Engels <lars.engels@0x20.net>
# $FreeBSD$

PORTNAME=	devede
DISTVERSION=	3.23.0
CATEGORIES=	multimedia
MASTER_SITES=	http://www.rastersoft.com/descargas/ \
		http://bsd-geek.de/FreeBSD/distfiles/

MAINTAINER=	lme@FreeBSD.org
COMMENT=	Create video DVDs, VCDs, sVCDs, or CVDs from any number of video files

RUN_DEPENDS=	ffmpeg:${PORTSDIR}/multimedia/ffmpeg \
		mencoder:${PORTSDIR}/multimedia/mencoder \
		spumux:${PORTSDIR}/multimedia/dvdauthor \
		vcdimager:${PORTSDIR}/multimedia/vcdimager \
		cdrecord:${PORTSDIR}/sysutils/cdrtools

USE_BZIP2=	yes
USE_GNOME=	pygtk2
USES=		iconv
USE_PYTHON=	yes
NO_BUILD=	yes

OPTIONS_DEFINE=	IBUS NLS
OPTIONS_DEFAULT=	IBUS
IBUS_DESC=	iBus support

DEJAVU_FONTSDIR=	${LOCALBASE}/lib/X11/fonts/dejavu
DEJAVU_FONTFILE=	${DEJAVU_FONTSDIR}/DejaVuSans.ttf

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MIBUS}
RUN_DEPENDS+=	ibus-daemon:${PORTSDIR}/textproc/ibus
.endif

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
.endif

PORTDOCS=	*

post-patch:
# Fix general locations
	@${REINPLACE_CMD} -E \
		-e 's|%%PREFIX%%|${PREFIX}|' \
		-e 's|%%PORTNAME%%|${PORTNAME}|' \
		-e 's|%%DATADIR%%|${DATADIR}|' \
		-e 's|%%DOCSDIR%%|${DOCSDIR}|' \
		${WRKSRC}/devede.py
	@${REINPLACE_CMD} -e 's|bash|sh|' ${WRKSRC}/devede-debug
# Fix font location
	@${REINPLACE_CMD} -E \
		-e 's,/usr/share/fonts/truetype/ttf-dejavu/(DejaVuSans|dejavusans).ttf,${DEJAVU_FONTFILE},g' \
		${WRKSRC}/devede_fonts.py

do-install:
# File locations in devede are a mess...
	@${INSTALL_SCRIPT} ${WRKSRC}/devede.py ${PREFIX}/bin/devede
	@${INSTALL_SCRIPT} ${WRKSRC}/devede-debug ${PREFIX}/bin/

	@${MKDIR} ${DATADIR}
	@${INSTALL_DATA} ${WRKSRC}/devedesans.ttf ${DATADIR}
	@${INSTALL_DATA} ${WRKSRC}/devede.svg ${DATADIR}

	@${MKDIR} ${DATADIR}/interface
	@(cd ${WRKSRC}/interface && ${FIND} . -type f -exec ${INSTALL_DATA} "{}" ${DATADIR} \;)

	@(cd ${WRKSRC}/pixmaps/ && ${FIND} . -depth 1 -type f \
		-exec ${INSTALL_DATA} "{}" ${DATADIR} \;)

	@${MKDIR} ${DATADIR}/backgrounds
	@(cd ${WRKSRC}/pixmaps/backgrounds && ${FIND} . -type f \
		-exec ${INSTALL_DATA} "{}" "${DATADIR}/backgrounds/{}" \;)

	@${MKDIR} ${DESKTOPDIR}
	@${INSTALL_DATA} ${WRKSRC}/devede.desktop ${DESKTOPDIR}

	@${MKDIR} ${PREFIX}/lib/${PORTNAME}
	@(cd ${WRKSRC} && ${FIND} . -depth 1 -type f -name "devede_*.py" \
			-exec ${INSTALL_SCRIPT} "{}" "${PREFIX}/lib/${PORTNAME}/{}" \;)

	@${INSTALL_DATA} ${WRKSRC}/devede.svg ${PREFIX}/share/pixmaps

.if ${PORT_OPTIONS:MNLS}
	@${INSTALL_DATA} ${WRKSRC}/po/ca.mo ${PREFIX}/share/locale/ca/LC_MESSAGES/devede.mo
	@${INSTALL_DATA} ${WRKSRC}/po/cs_CZ.mo ${PREFIX}/share/locale/cs/LC_MESSAGES/devede.mo
	@${INSTALL_DATA} ${WRKSRC}/po/da.mo ${PREFIX}/share/locale/da/LC_MESSAGES/devede.mo
	@${INSTALL_DATA} ${WRKSRC}/po/de_DE.mo ${PREFIX}/share/locale/de/LC_MESSAGES/devede.mo
	@${INSTALL_DATA} ${WRKSRC}/po/el.mo ${PREFIX}/share/locale/el/LC_MESSAGES/devede.mo
	@${INSTALL_DATA} ${WRKSRC}/po/es.mo ${PREFIX}/share/locale/es/LC_MESSAGES/devede.mo
	@${INSTALL_DATA} ${WRKSRC}/po/fr.mo ${PREFIX}/share/locale/fr/LC_MESSAGES/devede.mo
	@${INSTALL_DATA} ${WRKSRC}/po/gl.mo ${PREFIX}/share/locale/gl/LC_MESSAGES/devede.mo
	@${INSTALL_DATA} ${WRKSRC}/po/hu_HU.mo ${PREFIX}/share/locale/it/LC_MESSAGES/devede.mo
	@${INSTALL_DATA} ${WRKSRC}/po/it_IT.mo ${PREFIX}/share/locale/it/LC_MESSAGES/devede.mo
	@${INSTALL_DATA} ${WRKSRC}/po/nb_NO.mo ${PREFIX}/share/locale/nb/LC_MESSAGES/devede.mo
	@${INSTALL_DATA} ${WRKSRC}/po/nl.mo ${PREFIX}/share/locale/nl/LC_MESSAGES/devede.mo
	@${INSTALL_DATA} ${WRKSRC}/po/pl.mo ${PREFIX}/share/locale/pl/LC_MESSAGES/devede.mo
	@${INSTALL_DATA} ${WRKSRC}/po/pt_BR.mo ${PREFIX}/share/locale/pt_BR/LC_MESSAGES/devede.mo
	@${INSTALL_DATA} ${WRKSRC}/po/pt_PT.mo ${PREFIX}/share/locale/pt_PT/LC_MESSAGES/devede.mo
	@${INSTALL_DATA} ${WRKSRC}/po/ru.mo ${PREFIX}/share/locale/ru/LC_MESSAGES/devede.mo
	@${INSTALL_DATA} ${WRKSRC}/po/sk.mo ${PREFIX}/share/locale/sk/LC_MESSAGES/devede.mo
	@${INSTALL_DATA} ${WRKSRC}/po/sv.mo ${PREFIX}/share/locale/sv/LC_MESSAGES/devede.mo
	@${INSTALL_DATA} ${WRKSRC}/po/zh_CN.mo ${PREFIX}/share/locale/zh_CN/LC_MESSAGES/devede.mo
	@${INSTALL_DATA} ${WRKSRC}/po/zh_TW.mo ${PREFIX}/share/locale/zh_TW/LC_MESSAGES/devede.mo
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}/html
	@${INSTALL_DATA} ${WRKSRC}/docs/html/* ${DOCSDIR}/html
.endif

.include <bsd.port.mk>
