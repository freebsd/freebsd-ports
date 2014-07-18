# Created by: Dirk Froemberg <dirk@FreeBSD.org>
# $FreeBSD$

PORTNAME=	httrack
PORTVERSION=	3.48.18
CATEGORIES=	www
MASTER_SITES=	http://download.httrack.com/ \
		http://mirror.httrack.com/historical/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Easy-to-use offline browser utility and website copier

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

OPTIONS_DEFINE=	DOCS ICONS
OPTIONS_SUB=	yes

CONFIGURE_ARGS=	--docdir=${DOCSDIR} --with-zlib=/usr
CPPFLAGS+=	-I${LOCALBASE}/include
GNU_CONFIGURE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib
USE_LDCONFIG=	${PREFIX}/lib/httrack
USES=		gmake iconv libtool shebangfix

PORTDATA=	*
PORTDOCS=	*

SHEBANG_FILES=	src/webhttrack

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MICONS}
INSTALLS_ICONS=	yes
.endif

post-patch:
	@${REINPLACE_CMD} -e '/DEFAULT_CFLAGS=/ s|-O -g3 ||g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e '/ install-data-hook/d' ${WRKSRC}/html/Makefile.in
	@${REINPLACE_CMD} -e 's|/usr/share|${PREFIX}/share|' ${WRKSRC}/html/server/div/WebHTTrack*

post-install:
	${INSTALL_DATA} ${WRKSRC}/html/httrack.css ${STAGEDIR}${DOCSDIR}/httrack.css
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lib*.so ${STAGEDIR}${PREFIX}/lib/httrack/lib*.so

.include <bsd.port.mk>
