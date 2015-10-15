# Created by: Dirk Froemberg <dirk@FreeBSD.org>
# $FreeBSD$

PORTNAME=	httrack
PORTVERSION=	3.48.21
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://download.httrack.com/ \
		http://mirror.httrack.com/ \
		http://mirror.httrack.com/historical/ \
		LOCAL/sunpoet

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
USE_OPENSSL=	yes
USES=		alias execinfo gmake iconv libtool shebangfix

PORTDATA=	*
PORTDOCS=	*

SHEBANG_FILES=	src/webhttrack

ICONS_VARS=	INSTALLS_ICONS=yes

.include <bsd.port.pre.mk>

.if empty(ICONV_LIB)
CONFIGURE_ARGS+=ac_cv_lib_iconv_iconv=no
.else
CONFIGURE_ARGS+=ac_cv_lib_iconv_iconv=yes
.endif

post-patch:
	@${REINPLACE_CMD} -e '/ install-data-hook/d' ${WRKSRC}/html/Makefile.in
	@${REINPLACE_CMD} -e 's|/usr/share|${PREFIX}/share|' ${WRKSRC}/html/server/div/WebHTTrack*

post-install:
	${INSTALL_DATA} ${WRKSRC}/html/httrack.css ${STAGEDIR}${DOCSDIR}/httrack.css

.include <bsd.port.post.mk>
