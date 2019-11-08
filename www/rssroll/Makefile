# $FreeBSD$

PORTNAME=	rssroll
PORTVERSION=	0.6.2
CATEGORIES=	www

MAINTAINER=	koue@chaosophia.net
COMMENT=	RSS collector in C

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libcurl.so:ftp/curl

USES=		gnome sqlite:3
USE_GNOME=	libxml2

CEZ_VERSION=	1.05
USE_GITHUB=	yes
GH_ACCOUNT=	koue

GH_PROJECT=	rssroll:rssroll \
		libcez:libcez
GH_TAGNAME=	${CEZ_VERSION}:libcez

CFLAGS+=	-I${WRKSRC_libcez}/src/config \
		-I${WRKSRC_libcez}/src/fossil \
		-I${WRKSRC_libcez}/src/misc

LDFLAGS+=	-L${WRKSRC_libcez}/src/config \
		-L${WRKSRC_libcez}/src/fossil \
		-L${WRKSRC_libcez}/src/misc

pre-configure:
	@(cd ${WRKSRC_libcez} && ${SETENV} ${MAKE_ENV} ${MAKE})

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/rssroll ${STAGEDIR}${PREFIX}/bin
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "html css" ${STAGEDIR}${PREFIX}/www/rssroll/)
	${INSTALL_PROGRAM} ${WRKSRC}/src/index.cgi ${STAGEDIR}${PREFIX}/www/rssroll/index.cgi
	${INSTALL_DATA} ${WRKSRC}/rssrollrc ${STAGEDIR}${PREFIX}/etc/rssrollrc.sample

.include <bsd.port.mk>
