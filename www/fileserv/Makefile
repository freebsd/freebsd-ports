PORTNAME=	fileserv
PORTVERSION=	1.1
CATEGORIES=	www
MASTER_SITES=	https://download.gnu.org.ua/release/fileserv/

MAINTAINER=	zeus@gnu.org.ua
COMMENT=	Simple HTTP server for serving static files
WWW=		https://puszcza.gnu.org.ua/projects/fileserv

LICENSE=	GPLv3+

LIB_DEPENDS=	libmicrohttpd.so:www/libmicrohttpd

USES=		gmake localbase tar:xz
GNU_CONFIGURE=	yes

PLIST_FILES=	@sample\ etc/${PORTNAME}.conf.sample \
		sbin/${PORTNAME} share/man/man8/${PORTNAME}.8.gz
PORTDOCS=	ChangeLog NEWS README

OPTIONS_DEFINE=	DOCS

post-install:
	${MV} ${STAGEDIR}${PREFIX}/etc/${PORTNAME}.conf \
		${STAGEDIR}${PREFIX}/etc/${PORTNAME}.conf.sample

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
