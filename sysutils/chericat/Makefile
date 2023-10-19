PORTNAME=	chericat
PORTVERSION=	0.0.d${SNAPDATE}
CATEGORIES=	sysutils

MAINTAINER=	brooks@FreeBSD.org
COMMENT=	Capability Analysis Tool for CHERI
WWW=		https://github.com/CTSRD-CHERI/chericat

LICENSE=	BSD2CLAUSE
LICENSE_FILE_BSD2CLAUSE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_PROJECT=	chericat
GH_ACCOUNT=	CTSRD-CHERI
GH_TAGNAME=	${CHERICAT_COMMIT}

LIB_DEPENDS=	libsqlite3.so:databases/sqlite3

PLIST=
PLIST_FILES=	bin/chericat

.include "Makefile.snapshot"

.include <bsd.port.pre.mk>

.if !${ABI:Mpurecap}
IGNORE=		pure capability program
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/chericat ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.post.mk>
