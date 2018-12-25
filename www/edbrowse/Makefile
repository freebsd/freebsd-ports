# $FreeBSD$

PORTNAME=	edbrowse
DISTVERSIONPREFIX=	v
DISTVERSION=	3.7.4
PORTREVISION=	1
CATEGORIES=	www editors

MAINTAINER=	alfix86@gmail.com
COMMENT=	Line-oriented Web browser and text editor

LICENSE=	GPLv2

LIB_DEPENDS=	libpcre.so:devel/pcre \
		libcurl.so:ftp/curl \
		libtidy.so:www/tidy-lib \
		libtidy5.so:www/tidy-html5 \
		libduktape.so:lang/duktape-lib

USES=		cmake:insource compiler:c11 perl5 readline
USE_PERL5=	build
USE_GITHUB=	yes

GH_ACCOUNT=	CMB

PLIST_FILES=	bin/${PORTNAME} \
		man/man1/${PORTNAME}.1.gz

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_MAN} ${WRKSRC}/doc/man-edbrowse-freebsd.1 ${STAGEDIR}${MAN1PREFIX}/man/man1/${PORTNAME}.1
	${INSTALL_PROGRAM} ${WRKSRC}/edbrowse ${STAGEDIR}${PREFIX}/bin

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CHANGES ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/COPYING ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc && \
		${FIND} . \( -name setup.ebrc -or -name "man-edbrowse*" \) -delete  && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
