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
# Do not extract CLEARTYPE distfile
EXTRACT_ONLY=	${_DISTFILES:M*32*} ${_DISTFILES:M*CAB*} ${_DISTFILES:M*EXE*}

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	TrueType core fonts for the Web
WWW=		https://corefonts.sourceforge.net/

# Restrictive license - cannot sell for profit or distribute in modified form
LICENSE=	EULA
LICENSE_NAME=	End User License Agreement
LICENSE_FILE=	${WRKSRC}/licen.txt
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

USES=		fonts

EXTRACT_AFTER_ARGS=	--include '*.[tT][tT][fF]' \
			--no-same-owner --no-same-permissions

NO_WRKSUBDIR=	yes
NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	EXTRAFONTS CLEARTYPE NEWVERDANA DOCS COMIC
OPTIONS_DEFAULT=COMIC
OPTIONS_SUB=	yes

CLEARTYPE_DESC=		Install ClearType fonts
COMIC_DESC=		Install Comic Sans
EXTRAFONTS_DESC=	Fonts licensed under MS Windows license
NEWVERDANA_DESC=	Install y2006 version of Verdana (broken bold N, W)

CLEARTYPE_DISTFILES=	PowerPointViewer.exe:group3
EXTRAFONTS_DISTFILES=	IELPKTH.CAB:group2

.include <bsd.port.options.mk>

pre-extract-CLEARTYPE-on:
	${MKDIR} ${EXTRACT_WRKDIR}
	${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}/${_DISTFILES:MPowerPointViewer*} --include eula.txt -C ${EXTRACT_WRKDIR} --no-same-owner --no-same-permissions
	${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}/${_DISTFILES:MPowerPointViewer*} -O --include ppviewer.cab | ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} - -C ${EXTRACT_WRKDIR} ${EXTRACT_AFTER_ARGS}

post-extract:
	${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}/${_DISTFILES:Mwebdin32*} --include *.TXT -C ${EXTRACT_WRKDIR} --no-same-owner --no-same-permissions
.if ${PORT_OPTIONS:MNEWVERDANA}
	${RM} ${WRKSRC}/Verdan*.TTF
.else
	${RM} ${WRKSRC}/Verdan*.ttf
.endif
	@cd ${WRKSRC} && for f in *; do \
	    ${MV} "$$f" `${ECHO_CMD} "$$f" | ${TR} '[:upper:]' '[:lower:]'`; \
	done

post-extract-COMIC-off:
	${RM} ${WRKSRC}/comic.ttf ${WRKSRC}/comicbd.ttf

post-extract-EXTRAFONTS-off:
	${RM} ${WRKSRC}/tahoma.ttf ${WRKSRC}/tahomabd.ttf

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${STAGEDIR}${FONTSDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/licen.txt ${STAGEDIR}${DOCSDIR}/LICENSE

post-install-CLEARTYPE-on:
	${INSTALL_DATA} ${WRKSRC}/eula.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
