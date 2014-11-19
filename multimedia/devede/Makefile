# Created by: Lars Engels <lars.engels@0x20.net>
# $FreeBSD$

PORTNAME=	devede
DISTVERSION=	3.23.0
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	http://www.rastersoft.com/descargas/ \
		http://bsd-geek.de/FreeBSD/distfiles/

MAINTAINER= ports@FreeBSD.org
COMMENT=	Create video DVDs, VCDs, sVCDs, or CVDs from any number of video files

RUN_DEPENDS=	ffmpeg:${PORTSDIR}/multimedia/ffmpeg \
		mencoder:${PORTSDIR}/multimedia/mencoder \
		spumux:${PORTSDIR}/multimedia/dvdauthor \
		vcdimager:${PORTSDIR}/multimedia/vcdimager \
		cdrecord:${PORTSDIR}/sysutils/cdrtools

USE_GNOME=	pygtk2
USES=		iconv python tar:bzip2
NO_BUILD=	yes

OPTIONS_DEFINE=	IBUS NLS
OPTIONS_DEFAULT=	IBUS
IBUS_DESC=	iBus support

DEJAVU_FONTSDIR=	${LOCALBASE}/lib/X11/fonts/dejavu
DEJAVU_FONTFILE=	${DEJAVU_FONTSDIR}/DejaVuSans.ttf

IBUS_RUN_DEPENDS=	ibus-daemon:${PORTSDIR}/textproc/ibus
NLS_USES=	gettext
OPTIONS_SUB=	yes

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
	${INSTALL_SCRIPT} ${WRKSRC}/devede.py ${STAGEDIR}${PREFIX}/bin/devede
	${INSTALL_SCRIPT} ${WRKSRC}/devede-debug ${STAGEDIR}${PREFIX}/bin/

	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/devedesans.ttf ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/devede.svg ${STAGEDIR}${DATADIR}

	@${MKDIR} ${STAGEDIR}${DATADIR}/interface
	(cd ${WRKSRC}/interface && ${FIND} . -type f -exec ${INSTALL_DATA} "{}" ${STAGEDIR}${DATADIR} \;)

	(cd ${WRKSRC}/pixmaps/ && ${FIND} . -depth 1 -type f \
		-exec ${INSTALL_DATA} "{}" ${STAGEDIR}${DATADIR} \;)

	@${MKDIR} ${STAGEDIR}${DATADIR}/backgrounds
	(cd ${WRKSRC}/pixmaps/backgrounds && ${FIND} . -type f \
		-exec ${INSTALL_DATA} "{}" "${STAGEDIR}${DATADIR}/backgrounds/{}" \;)

	@${MKDIR} ${STAGEDIR}${DESKTOPDIR}
	${INSTALL_DATA} ${WRKSRC}/devede.desktop ${STAGEDIR}${DESKTOPDIR}

	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}
	(cd ${WRKSRC} && ${FIND} . -depth 1 -type f -name "devede_*.py" \
			-exec ${INSTALL_SCRIPT} "{}" "${STAGEDIR}${PREFIX}/lib/${PORTNAME}/{}" \;)

	${INSTALL_DATA} ${WRKSRC}/devede.svg ${STAGEDIR}${PREFIX}/share/pixmaps

	${INSTALL_DATA} ${WRKSRC}/po/ca.mo ${STAGEDIR}${PREFIX}/share/locale/ca/LC_MESSAGES/devede.mo
	${INSTALL_DATA} ${WRKSRC}/po/cs_CZ.mo ${STAGEDIR}${PREFIX}/share/locale/cs/LC_MESSAGES/devede.mo
	${INSTALL_DATA} ${WRKSRC}/po/da.mo ${STAGEDIR}${PREFIX}/share/locale/da/LC_MESSAGES/devede.mo
	${INSTALL_DATA} ${WRKSRC}/po/de_DE.mo ${STAGEDIR}${PREFIX}/share/locale/de/LC_MESSAGES/devede.mo
	${INSTALL_DATA} ${WRKSRC}/po/el.mo ${STAGEDIR}${PREFIX}/share/locale/el/LC_MESSAGES/devede.mo
	${INSTALL_DATA} ${WRKSRC}/po/es.mo ${STAGEDIR}${PREFIX}/share/locale/es/LC_MESSAGES/devede.mo
	${INSTALL_DATA} ${WRKSRC}/po/fr.mo ${STAGEDIR}${PREFIX}/share/locale/fr/LC_MESSAGES/devede.mo
	${INSTALL_DATA} ${WRKSRC}/po/gl.mo ${STAGEDIR}${PREFIX}/share/locale/gl/LC_MESSAGES/devede.mo
	${INSTALL_DATA} ${WRKSRC}/po/hu_HU.mo ${STAGEDIR}${PREFIX}/share/locale/it/LC_MESSAGES/devede.mo
	${INSTALL_DATA} ${WRKSRC}/po/it_IT.mo ${STAGEDIR}${PREFIX}/share/locale/it/LC_MESSAGES/devede.mo
	${INSTALL_DATA} ${WRKSRC}/po/nb_NO.mo ${STAGEDIR}${PREFIX}/share/locale/nb/LC_MESSAGES/devede.mo
	${INSTALL_DATA} ${WRKSRC}/po/nl.mo ${STAGEDIR}${PREFIX}/share/locale/nl/LC_MESSAGES/devede.mo
	${INSTALL_DATA} ${WRKSRC}/po/pl.mo ${STAGEDIR}${PREFIX}/share/locale/pl/LC_MESSAGES/devede.mo
	${INSTALL_DATA} ${WRKSRC}/po/pt_BR.mo ${STAGEDIR}${PREFIX}/share/locale/pt_BR/LC_MESSAGES/devede.mo
	${INSTALL_DATA} ${WRKSRC}/po/pt_PT.mo ${STAGEDIR}${PREFIX}/share/locale/pt_PT/LC_MESSAGES/devede.mo
	${INSTALL_DATA} ${WRKSRC}/po/ru.mo ${STAGEDIR}${PREFIX}/share/locale/ru/LC_MESSAGES/devede.mo
	${INSTALL_DATA} ${WRKSRC}/po/sk.mo ${STAGEDIR}${PREFIX}/share/locale/sk/LC_MESSAGES/devede.mo
	${INSTALL_DATA} ${WRKSRC}/po/sv.mo ${STAGEDIR}${PREFIX}/share/locale/sv/LC_MESSAGES/devede.mo
	${INSTALL_DATA} ${WRKSRC}/po/zh_CN.mo ${STAGEDIR}${PREFIX}/share/locale/zh_CN/LC_MESSAGES/devede.mo
	${INSTALL_DATA} ${WRKSRC}/po/zh_TW.mo ${STAGEDIR}${PREFIX}/share/locale/zh_TW/LC_MESSAGES/devede.mo
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/html
	${INSTALL_DATA} ${WRKSRC}/docs/html/* ${STAGEDIR}${DOCSDIR}/html

.include <bsd.port.mk>
