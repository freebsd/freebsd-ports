PORTNAME=	edbrowse
DISTVERSIONPREFIX=	v
DISTVERSION=	3.8.7
PORTREVISION=	1
CATEGORIES=	www editors

MAINTAINER=	alfix86@gmail.com
COMMENT=	Line-oriented web browser and text editor
WWW=		https://edbrowse.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libquickjs.so:lang/quickjs \
		libodbc.so:databases/unixODBC \
		libpcre2-8.so:devel/pcre2

USES=		compiler:c11 gmake perl5 pkgconfig readline ssl
USE_PERL5=	build
USE_GITHUB=	yes

MAKEFILE=	makefile

GH_ACCOUNT=	CMB

PLIST_FILES=	bin/${PORTNAME} \
		man/man1/${PORTNAME}.1.gz

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_MAN} ${WRKSRC}/doc/man-edbrowse-freebsd.1 ${STAGEDIR}${MAN1PREFIX}/man/man1/${PORTNAME}.1
	${INSTALL_PROGRAM} ${WRKSRC}/src/edbrowse ${STAGEDIR}${PREFIX}/bin

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CHANGES ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc && \
		${FIND} . \( -name article.wikipedia -or -name "man-edbrowse*" \) -delete  && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
