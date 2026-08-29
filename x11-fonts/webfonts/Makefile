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
WWW=		https://corefonts.sourceforge.net/

# Restrictive license - cannot sell for profit or distribute in modified form
LICENSE=	EULA
LICENSE_NAME=	End User License Agreement
LICENSE_FILE=	${WRKSRC}/licen.txt
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

USES=		fonts

NO_ARCH=	yes
NO_BUILD=	yes
SUB_FILES=	pkg-message

OPTIONS_DEFINE=	EXTRAFONTS CLEARTYPE NEWVERDANA DOCS COMIC
OPTIONS_DEFAULT=	COMIC
OPTIONS_SUB=	yes

CLEARTYPE_DESC=		Install ClearType fonts
COMIC_DESC=		Install Comic Sans
EXTRAFONTS_DESC=	Fonts licensed under MS Windows license
NEWVERDANA_DESC=	Install y2006 version of Verdana (broken bold N, W)

CLEARTYPE_DISTFILES=	PowerPointViewer.exe:group3
EXTRAFONTS_DISTFILES=	IELPKTH.CAB:group2

.include <bsd.port.options.mk>

# The distfiles are Microsoft self-extracting cabinets, which bsdtar reads
# directly, so no external extraction tool is needed.  Note that --exclude
# must precede the inclusion patterns: bsdtar stops parsing options at the
# first pattern argument and would otherwise treat it as one.
_FONT_CABS=	andale32.exe arialb32.exe comic32.exe courie32.exe \
		georgi32.exe impact32.exe webdin32.exe EUupdate.EXE
.if ${PORT_OPTIONS:MEXTRAFONTS}
_FONT_CABS+=	IELPKTH.CAB
.endif

_EXTRACT_CAB=	${TAR} -x --no-same-owner --no-same-permissions -C ${WRKSRC} -f

do-extract:
	@${MKDIR} ${WRKSRC}
# Verdana is held back here and taken from one of two sources below
.for cab in ${_FONT_CABS}
	@${_EXTRACT_CAB} ${_DISTDIR}/${cab} --exclude '[vV]*' '*.[tT][tT][fF]'
.endfor
	@${_EXTRACT_CAB} ${_DISTDIR}/webdin32.exe '*.[tT][xX][tT]'
.if ${PORT_OPTIONS:MNEWVERDANA}
	@${_EXTRACT_CAB} ${_DISTDIR}/EUupdate.EXE '[vV]*.[tT][tT][fF]'
.else
	@${_EXTRACT_CAB} ${_DISTDIR}/verdan32.exe '*.[tT][tT][fF]'
.endif
.if ${PORT_OPTIONS:MCLEARTYPE}
	@${_EXTRACT_CAB} ${_DISTDIR}/PowerPointViewer.exe 'ppviewer.cab' '*.[tT][xX][tT]'
	@${_EXTRACT_CAB} ${WRKSRC}/ppviewer.cab '*.[tT][tT][fF]'
	@${RM} ${WRKSRC}/ppviewer.cab
.endif
# The cabinets store mixed case names, the package installs lowercase ones
	@cd ${WRKSRC} && for f in *; do \
		l=$$(${ECHO_CMD} $${f} | ${TR} '[:upper:]' '[:lower:]'); \
		[ "$${f}" = "$${l}" ] || ${MV} -f "$${f}" "$${l}"; \
	done
.if ! ${PORT_OPTIONS:MCOMIC}
	@${RM} ${WRKSRC}/comic.ttf ${WRKSRC}/comicbd.ttf
.endif

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${STAGEDIR}${FONTSDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/licen.txt ${STAGEDIR}${DOCSDIR}/LICENSE

post-install-CLEARTYPE-on:
	${INSTALL_DATA} ${WRKSRC}/eula.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
