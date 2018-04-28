# $FreeBSD$

PORTNAME=	edbrowse
DISTVERSIONPREFIX=	v
DISTVERSION=	3.7.3
PORTREVISION=	1
CATEGORIES=	www editors

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES=	885fbc5f18ae61f9af9faa3e9d25c67a65148f6a.patch:-p1

MAINTAINER=	alfix86@gmail.com
COMMENT=	Line-oriented Web browser and text editor

LICENSE=	GPLv2

BROKEN_powerpc64=	fails to link: html.o: undefined reference to std::__cxx11::basic_string

LIB_DEPENDS=	libpcre.so:devel/pcre \
		libcurl.so:ftp/curl \
		libtidy.so:www/tidy-lib \
		libtidy5.so:www/tidy-html5 \
		libduktape.so:lang/duktape-lib

USES=		cmake:outsource perl5 readline
USE_GITHUB=	yes
GH_ACCOUNT=	CMB
USE_PERL5=	build

PLIST_FILES=	bin/${PORTNAME} \
		man/man1/${PORTNAME}.1.gz

OPTIONS_DEFINE=	DOCS

PORTDOCS=	*

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/man-edbrowse-debian.1 ${STAGEDIR}${MAN1PREFIX}/man/man1/${PORTNAME}.1

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CHANGES ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/COPYING ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc && \
		${FIND} . \( -name setup.ebrc -or -name "man-edbrowse*" \) -delete  && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
