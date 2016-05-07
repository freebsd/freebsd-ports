# Created by: "Waitman Gobble" <uzimac@da3m0n8t3r.com>
# $FreeBSD$

PORTNAME=	pkgcompare
PORTVERSION=	1.1
CATEGORIES=	ports-mgmt

MAINTAINER=	waitman@waitman.net
COMMENT=	Alternate to pkg upgrade

LICENSE=	PKG-COMPARE
LICENSE_NAME=	PKG-COMPARE BSD LICENSE
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

LIB_DEPENDS=	libpkg.so:${PKG_ORIGIN} \
		libsqlite3.so:databases/sqlite3

USE_GITHUB=	yes
GH_ACCOUNT=	waitman
GH_PROJECT=	pkg-compare
GH_TAGNAME=	418295d

BINARY=		pkg-compare

PORTDOCS=	*
PLIST_FILES=	man/man8/pkg-compare.8.gz \
		sbin/pkg-compare
SUB_FILES=	pkg-message

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${BINARY} ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/pkg-compare.8 \
		${STAGEDIR}${MAN8PREFIX}/man/man8

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${LICENSE_FILE} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
