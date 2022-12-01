PORTNAME=	portsdb
DISTVERSION=	0.2
CATEGORIES=	ports-mgmt

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Program that imports the FreeBSD ports tree into an SQLite database
WWW=		https://github.com/yurivict/freebsd-portsdb

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	sqlite3:databases/sqlite3

USE_GITHUB=	yes
GH_ACCOUNT=	yurivict
GH_PROJECT=	freebsd-portsdb

NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	bin/portsdb-import \
		libexec/${PORTNAME}/add-port-standalone.sh \
		libexec/${PORTNAME}/add-port.sh \
		libexec/${PORTNAME}/import.sh \
		libexec/${PORTNAME}/schema.sql

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/libexec/${PORTNAME}
.for f in import.sh add-port.sh add-port-standalone.sh
	${INSTALL_SCRIPT} ${WRKSRC}/${f} ${STAGEDIR}${PREFIX}/libexec/${PORTNAME}
.endfor
	${INSTALL_DATA} ${WRKSRC}/schema.sql ${STAGEDIR}${PREFIX}/libexec/${PORTNAME}
	${RLN} ${STAGEDIR}${PREFIX}/libexec/${PORTNAME}/import.sh ${STAGEDIR}${PREFIX}/bin/${PORTNAME}-import

.include <bsd.port.mk>
