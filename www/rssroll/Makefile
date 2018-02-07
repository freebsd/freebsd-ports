# $FreeBSD$

PORTNAME=	rssroll
PORTVERSION=	0.5
PORTREVISION=	1
CATEGORIES=	www

MAINTAINER=	koue@chaosophia.net
COMMENT=	RSS collector in C

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libxml2.so:textproc/libxml2 \
		libsqlite3.so:databases/sqlite3

USE_GITHUB=	yes
GH_ACCOUNT=	koue

GNU_CONFIGURE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/rssroll ${STAGEDIR}${PREFIX}/bin
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "html css" ${STAGEDIR}${PREFIX}/www/rssroll/)
	${INSTALL_PROGRAM} ${WRKSRC}/src/index.cgi ${STAGEDIR}${PREFIX}/www/rssroll/index.cgi
	${INSTALL_DATA} ${WRKSRC}/rssrollrc ${STAGEDIR}${PREFIX}/etc/rssrollrc.sample

.include <bsd.port.mk>
