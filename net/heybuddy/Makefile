# Created by: Beni Keller <navigium@grindcore.ch>
# $FreeBSD$

PORTNAME=	heybuddy
PORTVERSION=	0.2.4
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://launchpad.net/${PORTNAME}/${PORTVERSION:R}/${PORTVERSION}/+download/ \
		http://freebsd.grindcore.ch/distfiles/
EXTRACT_SUFX=	.tgz

MAINTAINER=	navigium@grindcore.ch
COMMENT=	Supposedly light, feature free identi.ca client

LICENSE=	GPLv3

FETCH_ARGS=	-Fpr
USE_PYTHON=	yes
USE_GNOME=	desktopfileutils pygtk2

DESKTOP_ENTRIES=	"Heybuddy" \
			"Light identi.ca client" \
			"${PORTNAME}" \
			"${PORTNAME}" \
			"" \
			false

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} \
		-e 's|%%PREFIX%%|${PREFIX}|g' \
		-e 's|%%DATADIR%%|${DATADIR}|g' \
		${WRKSRC}/${PORTNAME}.py
	@${MV} ${WRKSRC}/${PORTNAME}.py ${WRKDIR}

do-build:
	${PYTHON_CMD} -mcompileall ${WRKSRC}
	${PYTHON_CMD} -O -mcompileall ${WRKSRC}

do-install:
	@${MKDIR} ${DATADIR}
	cd ${WRKSRC} && ${INSTALL_DATA} README.txt *.py *.py[co] ${DATADIR}
	cd ${WRKDIR} && ${INSTALL_SCRIPT} ${PORTNAME}.py ${PREFIX}/bin/${PORTNAME}
	cd ${WRKSRC}/assets && ${INSTALL_DATA} icon64.png ${PREFIX}/share/pixmaps/${PORTNAME}.png
	@cd ${WRKSRC} && ${COPYTREE_SHARE} assets ${DATADIR}
.if ${PORT_OPTIONS:MNLS}
	@cd ${WRKSRC}/locales && ${COPYTREE_SHARE} . ${PREFIX}/share/locale
.endif

post-install:
	-@update-desktop-database

.include <bsd.port.mk>
