# Created by: Dirk Froemberg <dirk@FreeBSD.org>
# $FreeBSD$

PORTNAME=	httrack
PORTVERSION=	3.48.1
CATEGORIES=	www
MASTER_SITES=	http://download.httrack.com/ \
		http://mirror.httrack.com/historical/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Easy-to-use offline browser utility and website copier

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

OPTIONS_DEFINE=	DOCS

CONFIGURE_ARGS=	--docdir="${DOCSDIR}"
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	${PREFIX}/lib/${PORTNAME}
USES=		gmake iconv

PORTDATA=	*
PORTDOCS=	*

post-patch:
	@${REINPLACE_CMD} -e '/DEFAULT_CFLAGS=/ s|-O -g3 ||g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e '/ install-data-hook/d' ${WRKSRC}/html/Makefile.in
	@${REINPLACE_CMD} -e 's|/usr/share|${PREFIX}/share|' ${WRKSRC}/html/server/div/WebHTTrack*

post-install:
	${INSTALL_DATA} ${WRKSRC}/html/httrack.css ${STAGEDIR}${DOCSDIR}/httrack.css

.include <bsd.port.mk>
