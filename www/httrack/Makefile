PORTNAME=	httrack
PORTVERSION=	3.49.4
CATEGORIES=	www

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Easy-to-use offline browser utility and website copier
WWW=		https://www.httrack.com/ \
		https://github.com/xroche/httrack

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

USES=		alias cpe gmake iconv libtool shebangfix ssl

CONFIGURE_ARGS=	--docdir=${DOCSDIR} --with-zlib=/usr
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	${PREFIX}/lib/httrack

USE_GITHUB=	yes
GH_ACCOUNT=	xroche
GH_TUPLE=	xroche:coucal:73ada07:xroche_coucal/src/coucal

SHEBANG_FILES=	src/webhttrack

OPTIONS_DEFINE=	DOCS ICONS
OPTIONS_SUB=	yes

ICONS_USES=	gnome

.include <bsd.port.options.mk>

.if empty(ICONV_LIB)
CONFIGURE_ARGS+=ac_cv_lib_iconv_iconv=no
.else
CONFIGURE_ARGS+=ac_cv_lib_iconv_iconv=yes
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share|${PREFIX}/share|' ${WRKSRC}/html/server/div/WebHTTrack*
	@${REINPLACE_CMD} -e 's|gcc|${CC}|; s|-ldl ||' ${WRKSRC}/src/coucal/Makefile

post-install:
	${RM} ${STAGEDIR}${DATADIR}/html

post-install-DOCS-off:
# See PR/208875 for details
	${MKDIR} ${STAGEDIR}${DATADIR}/html/

post-install-DOCS-on:
	${INSTALL_DATA} ${WRKSRC}/html/httrack.css ${STAGEDIR}${DOCSDIR}/
	${RLN} ${STAGEDIR}${DOCSDIR} ${STAGEDIR}${DATADIR}/html

.include <bsd.port.mk>
