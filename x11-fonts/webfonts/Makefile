# Created by: Konstantinos Konstantinidis <kkonstan@daemon.gr>
# $FreeBSD$

PORTNAME=	webfonts
PORTVERSION=	0.30
PORTREVISION=	10
CATEGORIES=	x11-fonts
MASTER_SITES=	SF/corefonts/the%20fonts/final:group1 \
		ftp://ftp.botik.ru/rented/znamensk/distributions/ftp.vsu.ru/pub/tex/font-packs/mscore/:group1 \
		http://download.microsoft.com/download/ie6sp1/finrel/6_sp1/W98NT42KMeXP/EN-US/:group2
DISTFILES=	andale32.exe:group1 arial32.exe:group1 arialb32.exe:group1 \
		comic32.exe:group1 courie32.exe:group1 georgi32.exe:group1 \
		impact32.exe:group1 times32.exe:group1 trebuc32.exe:group1 \
		verdan32.exe:group1 webdin32.exe:group1
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	TrueType core fonts for the Web

EXTRACT_DEPENDS=cabextract:archivers/cabextract

USES=		fonts
NO_BUILD=	yes
RESTRICTED=	Restrictive license - cannot sell for profit or distribute in modified form

EXTRACT_CMD=		${LOCALBASE}/bin/cabextract
EXTRACT_BEFORE_ARGS=	-qLF '*.ttf' -d ${WRKSRC}
EXTRACT_AFTER_ARGS=

OPTIONS_DEFINE=	EXTRAFONTS
OPTIONS_SUB=	yes

EXTRAFONTS_DESC=	Fonts licensed under MS Windows license
EXTRAFONTS_DISTFILES=	ielpkth.cab:group2

SUB_FILES=	pkg-message

.include <bsd.port.options.mk>

post-extract:
	${EXTRACT_CMD} -qLF '*.txt' -d ${WRKSRC} ${_DISTDIR}/webdin32.exe

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${STAGEDIR}${FONTSDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/licen.txt ${STAGEDIR}${DOCSDIR}/LICENSE

.include <bsd.port.mk>
