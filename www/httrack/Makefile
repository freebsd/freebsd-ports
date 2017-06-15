# Created by: Dirk Froemberg <dirk@FreeBSD.org>
# $FreeBSD$

PORTNAME=	httrack
PORTVERSION=	3.48.24
CATEGORIES=	www

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Easy-to-use offline browser utility and website copier

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

OPTIONS_DEFINE=	DOCS ICONS
OPTIONS_SUB=	yes

CONFIGURE_ARGS=	--docdir=${DOCSDIR} --with-zlib=/usr
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	${PREFIX}/lib/httrack
USES=		alias execinfo gmake iconv libtool localbase shebangfix ssl

PORTDATA=	*
PORTDOCS=	*

GH_TUPLE=	xroche:${PORTNAME}:a9a7aa6 \
		xroche:coucal:afd0a56:coucal/src/coucal
USE_GITHUB=	yes

SHEBANG_FILES=	src/webhttrack

ICONS_VARS=	INSTALLS_ICONS=yes

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
	${INSTALL_DATA} ${WRKSRC}/html/httrack.css ${STAGEDIR}${DOCSDIR}/

post-install-DOCS-off:
# make an empty directory instead of an invalid symbolic link to DOCSDIR
	${RM} ${STAGEDIR}${DATADIR}/html
	${MKDIR} ${STAGEDIR}${DATADIR}/html/

.include <bsd.port.mk>
