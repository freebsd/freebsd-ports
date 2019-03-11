# Created by: Konstantinos Konstantinidis <kkonstan@daemon.gr>
# $FreeBSD$

PORTNAME=	webfonts
PORTVERSION=	0.30
PORTREVISION=	14
CATEGORIES=	x11-fonts
MASTER_SITES=	SF/corefonts/the%20fonts/final:group1 \
		ftp://ftp.botik.ru/rented/znamensk/distributions/ftp.vsu.ru/pub/tex/font-packs/mscore/:group1 \
		SF/corefonts/OldFiles/:group2 \
		SF/mscorefonts2/cabs:group3
DISTFILES=	andale32.exe:group1 arialb32.exe:group1 comic32.exe:group1 \
		courie32.exe:group1 georgi32.exe:group1 impact32.exe:group1 \
		verdan32.exe:group1 webdin32.exe:group1 EUupdate.EXE:group3
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	TrueType core fonts for the Web

LICENSE=	EULA
LICENSE_NAME=	End User License Agreement
LICENSE_FILE=	${WRKSRC}/licen.txt
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

EXTRACT_DEPENDS=cabextract:archivers/cabextract

USES=		fonts
NO_BUILD=	yes
RESTRICTED=	Restrictive license - cannot sell for profit or distribute in modified form

EXTRACT_CMD=		${LOCALBASE}/bin/cabextract
EXTRACT_BEFORE_ARGS=	-qLF '[a-uw-z]*.ttf' -d ${WRKSRC}
EXTRACT_AFTER_ARGS=

OPTIONS_DEFINE=	EXTRAFONTS CLEARTYPE NEWVERDANA DOCS
OPTIONS_SUB=	yes

EXTRAFONTS_DESC=	Fonts licensed under MS Windows license
EXTRAFONTS_DISTFILES=	IELPKTH.CAB:group2

CLEARTYPE_DESC=	Install ClearType fonts
CLEARTYPE_DISTFILES=	PowerPointViewer.exe:group3

NEWVERDANA_DESC=	Install y2006 version of Verdana (broken bold N, W)

SUB_FILES=	pkg-message

.include <bsd.port.options.mk>

post-extract:
	${EXTRACT_CMD} -qLF '*.txt' -d ${WRKSRC} ${_DISTDIR}/webdin32.exe

post-extract-CLEARTYPE-on:
	${EXTRACT_CMD} -qLF '*.cab' -d ${WRKSRC} \
		${_DISTDIR}/PowerPointViewer.exe
	${EXTRACT_CMD} -qLF '*.txt' -d ${WRKSRC} \
		${_DISTDIR}/PowerPointViewer.exe
	${EXTRACT_CMD} -qLF '*.ttf' -d ${WRKSRC} ${WRKSRC}/ppviewer.cab

post-extract-NEWVERDANA-off:
	${EXTRACT_CMD} -qLF '*.ttf' -d ${WRKSRC} ${_DISTDIR}/verdan32.exe

post-extract-NEWVERDANA-on:
	${EXTRACT_CMD} -qLF 'v*.ttf' -d ${WRKSRC} ${_DISTDIR}/EUupdate.EXE

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${STAGEDIR}${FONTSDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/licen.txt ${STAGEDIR}${DOCSDIR}/LICENSE

post-install-CLEARTYPE-on:
	${INSTALL_DATA} ${WRKSRC}/eula.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
