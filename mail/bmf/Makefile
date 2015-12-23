# Created by: Sean Chittenden <seanc@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bmf
PORTVERSION=	0.9.4
PORTREVISION=	3
CATEGORIES=	mail
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fst Bayesian Mail Filter compatible with maildrop and procmail

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

HAS_CONFIGURE=	yes

OPTIONS_DEFINE=	BDB MYSQL DEBUG DOCS
OPTIONS_DEFAULT=BDB

BDB_USE=		BDB=40+
BDB_CONFIGURE_WITH=	libdb
BDB_CFLAGS=		-I${BDB_INCLUDE_DIR}
BDB_LDFLAGS=		-L${BDB_LIB_DIR}
BDB_CONFIGURE_ENV=	DB_LIBNAME=-l${BDB_LIB_NAME}

DEBUG_CONFIGURE_ON=	--debug=yes

MYSQL_USE=		MYSQL=client
MYSQL_CONFIGURE_WITH=	mysql

post-patch:
	@${REINPLACE_CMD} -e 's|@@CC|${CC}|;s|@@CXX|${CXX}|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's/: checkroot/: /g' ${WRKSRC}/Makefile.in

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/bmf
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/bmfconv

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
