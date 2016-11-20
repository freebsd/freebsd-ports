# $FreeBSD$

PORTNAME=	edbrowse
PORTVERSION=	3.5.1
PORTREVISION=	1
CATEGORIES=	www editors
MASTER_SITES=	http://the-brannons.com/edbrowse/ \
		http://rithmomachia.org/edbrowse/

MAINTAINER=	david.vionnet@vmailbox.org
COMMENT=	Line-oriented Web browser and text editor

LICENSE=	GPLv2

BUILD_DEPENDS=	${UNZIP_CMD}:archivers/unzip
LIB_DEPENDS=	libpcre.so:devel/pcre \
		libmozjs-24.so:lang/spidermonkey24 \
		libcurl.so:ftp/curl

USE_OPENSSL=	yes
USES=		compiler:c11 readline zip

OPTIONS_DEFINE=	DOCS

WRKBASE=	${WRKDIR}/${PORTNAME}-${PORTVERSION}
WRKSRC=		${WRKBASE}/src

MAKEFILE=	makefile.bsd

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/edbrowse ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKBASE}/doc/man-edbrowse-debian.1 ${STAGEDIR}${MAN1PREFIX}/man/man1/edbrowse.1

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKBASE}/CHANGES ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKBASE}/COPYING ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKBASE}/README ${STAGEDIR}${DOCSDIR}
	(cd ${WRKBASE}/doc && \
		${FIND} . \( -name setup.ebrc -or -name "man-edbrowse*" \) -delete  && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
