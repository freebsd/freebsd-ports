PORTNAME=	veracrypt
PORTVERSION=	1.26.29
CATEGORIES=	security
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME:S/v/V/:S/c/C/}%20${PORTVERSION}/Source%20Code
DISTNAME=	${PORTNAME:S/v/V/:S/c/C/}_${PORTVERSION}_Source

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Open-source disk encryption software based on Truecrypt
WWW=		https://www.veracrypt.fr/

BUILD_DEPENDS=	yasm:devel/yasm
LIB_DEPENDS=	libpcsclite.so:devel/pcsc-lite

LICENSE_FILE=	${DOCSDIR}/LICENSE

USES=		compiler:c++11-lang cpe desktop-file-utils fuse gmake iconv pkgconfig sudo tar:bz2
CPE_VENDOR=	idrix
USE_CXXSTD=	c++11
USE_WX=		3.0+
NO_WRKSUBDIR=	yes
BUILD_WRKSRC=	${WRKSRC}/src
ALL_TARGET=	#
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}
SUB_FILES=	pkg-message

MAKE_ENV+=	SOURCE_DATE_EPOCH=1780902000
OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
MAKE_ENV+=	LFLAGS=-Wl,-z,notext
.endif

post-patch:
	${REINPLACE_CMD} -e 's|wx-config|${WX_CONFIG}|g' ${WRKSRC}/src/Makefile
	${REINPLACE_CMD} -e 's|/usr/bin|${PREFIX}/bin|g' ${WRKSRC}/src/Setup/FreeBSD/veracrypt.desktop

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/Main/veracrypt ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/src/Setup/FreeBSD/veracrypt.desktop ${STAGEDIR}${PREFIX}/share/applications/
.	for RESO in 1024 128 16 256 48
		@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${RESO}x${RESO}/apps
		${INSTALL_DATA} ${WRKSRC}/src/Resources/Icons/VeraCrypt-${RESO}x${RESO}.png ${STAGEDIR}${PREFIX}/share/icons/hicolor/${RESO}x${RESO}/apps/${PORTNAME}.png
.	endfor
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps/
	${INSTALL_DATA} ${WRKSRC}/src/Resources/Icons/VeraCrypt.svg ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps/${PORTNAME}.svg

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/html
	${INSTALL_DATA} ${WRKSRC}/License.txt ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc/html && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/html

.include <bsd.port.post.mk>
