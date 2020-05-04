# Created by: jfitz
# $FreeBSD$

PORTNAME=	analog
PORTVERSION=	6.0
PORTREVISION=	12
PORTEPOCH=	1
CATEGORIES=	www
MASTER_SITES=	http://analog.gsp.com/ \
		http://fossies.org/unix/www/old/

MAINTAINER=	john@essenz.com
COMMENT=	Fast program for analysing WWW logfiles

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/Licence.txt

LIB_DEPENDS=	libgd.so:graphics/gd \
		libpng.so:graphics/png

USES=		jpeg
BUILD_WRKSRC=	${WRKSRC}/src

ALL_TARGET=	${PORTNAME}

SUB_FILES=	pkg-message

LIMGDIR?=	www/data/images
IMGDIR=		${PREFIX}/${LIMGDIR}
PLIST_SUB=	IMGDIR="${LIMGDIR}"

OPTIONS_DEFINE=	DOCS EXAMPLES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/analog ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/analog.man ${STAGEDIR}${MANPREFIX}/man/man1/analog.1
	${INSTALL_DATA} ${WRKSRC}/analog.cfg ${STAGEDIR}${PREFIX}/etc/analog.cfg.sample
	${MKDIR} ${STAGEDIR}${DATADIR}/lang
	${INSTALL_DATA} ${WRKSRC}/lang/* ${STAGEDIR}${DATADIR}/lang
	${MKDIR} ${STAGEDIR}${IMGDIR}
	${INSTALL_DATA} ${WRKSRC}/images/* ${STAGEDIR}${IMGDIR}

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/* ${STAGEDIR}${DOCSDIR}

do-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.cfg ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/anlgform.html ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/anlgform.pl ${STAGEDIR}${EXAMPLESDIR}
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/css
	${INSTALL_DATA} ${WRKSRC}/examples/css/Readme.txt ${STAGEDIR}${EXAMPLESDIR}/css
	${INSTALL_DATA} ${WRKSRC}/examples/css/default.css ${STAGEDIR}${EXAMPLESDIR}/css
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/css/jreeves
	${INSTALL_DATA} ${WRKSRC}/examples/css/jreeves/* ${STAGEDIR}${EXAMPLESDIR}/css/jreeves

.include <bsd.port.mk>
