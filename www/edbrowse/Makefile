PORTNAME=	edbrowse
DISTVERSIONPREFIX=	v
DISTVERSION=	3.8.12
CATEGORIES=	www editors accessibility

MAINTAINER=	alfix86@gmail.com
COMMENT=	Line-oriented web browser and text editor
WWW=		https://edbrowse.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libodbc.so:databases/unixODBC \
		libpcre2-8.so:devel/pcre2 \
		libquickjs.so:lang/quickjs

USES=		compiler:c11 gmake perl5 pkgconfig readline ssl
USE_GITHUB=	yes
USE_PERL5=	build

MAKEFILE=	makefile
MAKE_ARGS=	QUICKJS_INCLUDE=${LOCALBASE}/include/quickjs \
		QUICKJS_LIB=${LOCALBASE}/lib

PLIST_FILES=	bin/${PORTNAME} \
		share/man/man1/${PORTNAME}.1.gz

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_MAN} ${WRKSRC}/doc/man-edbrowse-freebsd.1 ${STAGEDIR}${PREFIX}/share/man/man1/${PORTNAME}.1
	${INSTALL_PROGRAM} ${WRKSRC}/src/edbrowse ${STAGEDIR}${PREFIX}/bin

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CHANGES ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc && \
		${FIND} . \( -name article.wikipedia -or -name "man-edbrowse*" \) -delete  && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
