PORTNAME=	purple-gowhatsapp
DISTVERSIONPREFIX=v
DISTVERSION=	1.13.0
CATEGORIES=	net-im

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	WhatsApp plugin for libpurple
WWW=		https://github.com/hoehermann/purple-gowhatsapp

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN=	downloads things at build time, which breaks under poudriere
LIB_DEPENDS=	libpurple.so:net-im/libpurple	\
		libopusfile.so:audio/opusfile

USES=	go:no_targets cmake dos2unix localbase:ldflags

OPTIONS_MULTI=			DB-backend
OPTIONS_MULTI_DB-backend=	SQLITE3 PGSQL MYSQL
OPTIONS_DEFAULT=SQLITE3
.for o in ${OPTIONS_MULTI_DB-backend}
$o_DESC=	Support use of $o for storing account information
.endfor

USE_GITHUB=	yep...
GH_ACCOUNT=	hoehermann
DOS2UNIX_GLOB=	CMake*.txt

CMAKE_ARGS=	-DPURPLE_INCLUDE_DIRS=${LOCALBASE}/include/libpurple	\
		-DPURPLE_LIBRARY_DIRS=${LOCALBASE}/lib	\
		-DPURPLE_PLUGIN_DIR=${PREFIX}/lib/purple-2 \
		-DPURPLE_DATA_DIR=${PREFIX}/share

post-patch-PGSQL-off:
	${REINPLACE_CMD} '/lib\/pq/d' ${WRKSRC}/src/go/login.go

post-patch-MYSQL-off:
	${REINPLACE_CMD} '/go-sql-driver\/mysql/d' ${WRKSRC}/src/go/login.go

post-patch-SQLITE3-off:
	${REINPLACE_CMD} '/mattn\/go-sqlite3/d' ${WRKSRC}/src/go/login.go

# The downloaded Go-files are read-only and the simple rm -f does not work
# against them (unless invoked as root). Here we relax the permissions first:
pre-clean:
	-@${FIND} ${WRKDIR} | ${XARGS} ${CHMOD} u+w

.include <bsd.port.mk>
