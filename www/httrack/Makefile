PORTNAME=	httrack
PORTVERSION=	3.50.3
CATEGORIES=	www
MASTER_SITES=	https://github.com/xroche/httrack/releases/download/${PORTVERSION}/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Easy-to-use offline browser utility and website copier
WWW=		https://www.httrack.com/ \
		https://github.com/xroche/httrack

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

USES=		cpe gmake iconv libtool shebangfix ssl

CONFIGURE_ARGS=	--docdir=${DOCSDIR} --with-zlib=/usr
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	${PREFIX}/lib/httrack

SHEBANG_FILES=	src/webhttrack.in

OPTIONS_DEFINE=	DOCS ICONS
OPTIONS_SUB=	yes

ICONS_USES=	gnome

.include <bsd.port.options.mk>

.if empty(ICONV_LIB)
CONFIGURE_ARGS+=ac_cv_lib_iconv_iconv=no
.else
CONFIGURE_ARGS+=ac_cv_lib_iconv_iconv=yes
.endif

post-install-DOCS-off:
# See PR/208875 for details
	${RM} ${STAGEDIR}${DATADIR}/html/doc
	${MKDIR} ${STAGEDIR}${DATADIR}/html/doc

post-install-DOCS-on:
	${INSTALL_DATA} ${WRKSRC}/html/httrack.css ${STAGEDIR}${DOCSDIR}/
	${RLN} ${STAGEDIR}${DOCSDIR} ${STAGEDIR}${DATADIR}/html

.include <bsd.port.mk>
