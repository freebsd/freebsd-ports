PORTNAME=	rssroll
PORTVERSION=	0.11.0
PORTREVISION=	1
CATEGORIES=	www

MAINTAINER=	koue@chaosophia.net
COMMENT=	RSS collector in C
WWW=		http://chaosophia.net/rssroll/

LICENSE=	BSD2CLAUSE

USES=		gnome sqlite:3
USE_GNOME=	libxml2

FSL_VERSION=	2.14
CEZ_VERSION=	1.13
RENDER_VERSION=	1.0
USE_GITHUB=	yes
GH_ACCOUNT=	koue

GH_PROJECT=	rssroll:rssroll \
		libfsl:libfsl \
		libcez:libcez \
		librender:librender
GH_TAGNAME=	${FSL_VERSION}:libfsl \
		${CEZ_VERSION}:libcez \
		${RENDER_VERSION}:librender

# XXX Static libraries with PIE are currently unsupported.
MAKE_ENV+=	WITHOUT_PIE=true

CFLAGS+=	-I${WRKSRC_libfsl}/src/base \
		-I${WRKSRC_libfsl}/src/db \
		-I${WRKSRC_libcez}/src/core \
		-I${WRKSRC_libcez}/src/misc \
		-I${WRKSRC_libcez}/src/queue \
		-I${WRKSRC_librender}/src

LDFLAGS+=	-L${WRKSRC_libfsl}/src/base \
		-L${WRKSRC_libfsl}/src/db \
		-L${WRKSRC_libcez}/src/core \
		-L${WRKSRC_libcez}/src/misc \
		-L${WRKSRC_libcez}/src/queue \
		-L${WRKSRC_librender}/src

post-patch:
	@${REINPLACE_CMD} -e "s|/etc/rssrollrc|${PREFIX}/etc/rssrollrc|" \
		${WRKSRC}/src/rss.h

pre-configure:
	@(cd ${WRKSRC_libfsl}/src/base && ${SETENV} ${MAKE_ENV} ${MAKE})
	@(cd ${WRKSRC_libfsl}/src/db && ${SETENV} ${MAKE_ENV} ${MAKE})
	@(cd ${WRKSRC_libcez}/src/core && ${SETENV} ${MAKE_ENV} ${MAKE})
	@(cd ${WRKSRC_libcez}/src/misc && ${SETENV} ${MAKE_ENV} ${MAKE})
	@(cd ${WRKSRC_libcez}/src/queue && ${SETENV} ${MAKE_ENV} ${MAKE})
	@(cd ${WRKSRC_librender}/src && ${SETENV} ${MAKE_ENV} ${MAKE})

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/rssroll ${STAGEDIR}${PREFIX}/bin
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "html css" ${STAGEDIR}${PREFIX}/www/rssroll/)
	${INSTALL_PROGRAM} ${WRKSRC}/src/index.cgi ${STAGEDIR}${PREFIX}/www/rssroll/index.cgi
	${INSTALL_DATA} ${WRKSRC}/etc/rssrollrc ${STAGEDIR}${PREFIX}/etc/rssrollrc.sample

.include <bsd.port.mk>
