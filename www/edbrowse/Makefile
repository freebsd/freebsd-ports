# $FreeBSD$

PORTNAME=	edbrowse
PORTVERSION=	3.5.1
PORTREVISION=	4
CATEGORIES=	www editors
MASTER_SITES=	http://the-brannons.com/edbrowse/ \
		http://rithmomachia.org/edbrowse/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Line-oriented Web browser and text editor

LICENSE=	GPLv2

BUILD_DEPENDS=	${UNZIP_CMD}:archivers/unzip
LIB_DEPENDS=	libpcre.so:devel/pcre \
		libmozjs-24.so:lang/spidermonkey24 \
		libcurl.so:ftp/curl

BROKEN_powerpc64=	fails to link: html.o: undefined reference to std::__cxx11::basic_string

USES=		compiler:c11 readline zip ssl

OPTIONS_DEFINE=	DOCS

WRKBASE=	${WRKDIR}/${PORTNAME}-${PORTVERSION}
WRKSRC=		${WRKBASE}/src

MAKEFILE=	makefile.bsd

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/edbrowse ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKBASE}/doc/man-edbrowse-debian.1 ${STAGEDIR}${MAN1PREFIX}/man/man1/edbrowse.1

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKBASE}/CHANGES ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKBASE}/COPYING ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKBASE}/README ${STAGEDIR}${DOCSDIR}
	(cd ${WRKBASE}/doc && \
		${FIND} . \( -name setup.ebrc -or -name "man-edbrowse*" \) -delete  && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
