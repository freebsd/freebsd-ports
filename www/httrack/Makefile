# Created by: Dirk Froemberg <dirk@FreeBSD.org>
# $FreeBSD$

PORTNAME=	httrack
PORTVERSION=	3.47.22
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
USE_GMAKE=	yes
USE_LDCONFIG=	${PREFIX}/lib ${PREFIX}/lib/${PORTNAME}
USES=		iconv

MAN1=		htsserver.1 httrack.1 proxytrack.1 webhttrack.1

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e '/DEFAULT_CFLAGS=/ s|-O -g3 ||g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e '/ install-data-hook/d' ${WRKSRC}/html/Makefile.in
	@${REINPLACE_CMD} -e 's|/usr/share|${PREFIX}/share|' ${WRKSRC}/html/server/div/WebHTTrack*
.if ! ${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} -e '/^SUBDIRS = / s| html||' ${WRKSRC}/Makefile.in
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${INSTALL_DATA} ${WRKSRC}/html/httrack.css ${DOCSDIR}/httrack.css
.endif

.include <bsd.port.mk>
