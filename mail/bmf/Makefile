# Created by: Sean Chittenden <seanc@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bmf
PORTVERSION=	0.84
CATEGORIES=	mail
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fst Bayesian Mail Filter compatible with maildrop and procmail

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

HAS_CONFIGURE=	yes
ALL_TARGET=	apps

OPTIONS_DEFINE=	BDB DEBUG DOCS MYSQL
OPTIONS_DEFAULT=BDB

BDB_USES=		bdb
BDB_CONFIGURE_WITH=	libdb
BDB_CFLAGS=		-I${BDB_INCLUDE_DIR}
BDB_LDFLAGS=		-L${BDB_LIB_DIR}
BDB_CONFIGURE_ENV=	DB_LIBNAME=-l${BDB_LIB_NAME}

DEBUG_CONFIGURE_ON=	--debug=yes

MYSQL_BUILD_DEPENDS=	mysql80-client>0:databases/mysql80-client
MYSQL_CONFIGURE_WITH=	mysql
MYSQL_VARS=		MAKE_ARGS=CFLAGS+="-I${WRKSRC} -I${LOCALBASE}/include" \
			LDFLAGS+=-L${LOCALBASE}/lib/mysql

post-patch:
	@${REINPLACE_CMD} -e 's|@@CC|${CC}|;s|@@CXX|${CXX}|' ${WRKSRC}/configure

do-install:
	(cd ${WRKSRC} ; ${INSTALL_PROGRAM} bmf bmfconv ${STAGEDIR}${PREFIX}/bin)

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/bmf ${STAGEDIR}${PREFIX}/bin/bmfconv

.include <bsd.port.mk>
