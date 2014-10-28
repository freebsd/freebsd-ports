# Created by: "Waitman Gobble" <uzimac@da3m0n8t3r.com>
# $FreeBSD$

PORTNAME=	pkgcompare
PORTVERSION=	1.1
CATEGORIES=	ports-mgmt
MASTER_SITES=	GH
DISTNAME=	${GH_ACCOUNT}-${GH_PROJECT}-${PORTVERSION}-0-g${GH_COMMIT}

MAINTAINER=	waitman@waitman.net
COMMENT=	Alternate to pkg upgrade

LICENSE=	PKG-COMPARE
LICENSE_NAME=	PKG-COMPARE BSD LICENSE
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	${_LICENSE_PERMS_DEFAULT}

LIB_DEPENDS=	libpkg.so:${PORTSDIR}/ports-mgmt/pkg \
		libsqlite3.so:${PORTSDIR}/databases/sqlite3

USE_GITHUB=	yes
GH_ACCOUNT=	waitman
GH_PROJECT=	pkg-compare
GH_TAGNAME=	418295d
GH_COMMIT=	${GH_TAGNAME}

WRKSRC=		${WRKDIR}/waitman-pkg-compare-${GH_TAGNAME}

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
