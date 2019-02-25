# $FreeBSD$

PORTNAME=	veracrypt
PORTVERSION=	1.23
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME:S/v/V/:S/c/C/}%20${PORTVERSION}/
DISTNAME=	${PORTNAME:S/v/V/:S/c/C/}_${PORTVERSION}_Source

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Open-source disk encryption software based on Truecrypt

BUILD_DEPENDS=	yasm:devel/yasm
RUN_DEPENDS=	${LOCALBASE}/bin/sudo:security/sudo

LICENSE_FILE=	${DOCSDIR}/LICENSE

USES=		compiler:c++11-lang desktop-file-utils fuse gmake iconv pkgconfig tar:bz2
USE_WX=		3.0+
NO_WRKSUBDIR=	yes
BUILD_WRKSRC=	${WRKSRC}/src
ALL_TARGET=	#
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}
SUB_FILES=	pkg-message

OPTIONS_DEFINE=	DOCS

post-patch:
	${REINPLACE_CMD} -e 's|wx-config|${WX_CONFIG}|g' ${WRKSRC}/src/Makefile
	${REINPLACE_CMD} -e 's|/usr/bin|${PREFIX}/bin|g' -e \
				's|Icon=veracrypt|Icon=VeraCrypt-16x16|g' ${WRKSRC}/src/Setup/FreeBSD/veracrypt.desktop

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/Main/veracrypt ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/src/Setup/FreeBSD/veracrypt.desktop ${STAGEDIR}${PREFIX}/share/applications/
	cd ${WRKSRC}/src/Resources/Icons && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/share/pixmaps "-name *\.xpm"

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/html
	${INSTALL_DATA} ${WRKSRC}/License.txt ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc/html && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/html

.include <bsd.port.mk>
