# Created by: "Waitman Gobble" <uzimac@da3m0n8t3r.com>
# $FreeBSD$

PORTNAME=	chucky
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	ports-mgmt

MAINTAINER=	waitman@waitman.net
COMMENT=	Port installed version check/report with shar archival

LICENSE=	CHUCKY
LICENSE_NAME=	CHUCKY BSD LICENSE
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

LIB_DEPENDS=	libpkg.so:${PKG_ORIGIN} \
		libsqlite3.so:databases/sqlite3

USE_GITHUB=	yes
GH_ACCOUNT=	waitman
GH_TAGNAME=	075defe

SUB_FILES=	pkg-message
SUB_LIST=	MAN7PREFIX="${MAN7PREFIX}"
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
