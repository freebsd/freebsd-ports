# Created by: Sean Chittenden <seanc@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bmf
PORTVERSION=	0.9.4
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fst Bayesian Mail Filter compatible with maildrop and procmail

OPTIONS_DEFINE=		BDB MYSQL DEBUG
OPTIONS_DEFAULT=	BDB
BDB_DESC=			Berkeley DB support (may specify w/ WITH_BDB_VER)
MYSQL_DESC=			Adds MySQL Support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MBDB}
USE_BDB=	40+
CFLAGS+=	-I${BDB_INCLUDE_DIR}
LDFLAGS+=	-L${BDB_LIB_DIR}
CONFIGURE_ARGS+=--with-libdb=yes
CONFIGURE_ENV+=	DB_LIBNAME=-l${BDB_LIB_NAME}
.else
CONFIGURE_ARGS+=--with-libdb=no
.endif
.if ${PORT_OPTIONS:MMYSQL}
USE_MYSQL=	client
CONFIGURE_ARGS+=--with-mysql
.endif

HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=	--without-package

.if ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=	--debug=yes
.endif

post-patch:
	${REINPLACE_CMD} -e 's/@@CC/${CC}/;s/@@CXX/${CXX}/' ${WRKSRC}/configure
	${REINPLACE_CMD} -e 's/: checkroot/: /g' ${WRKSRC}/Makefile.in

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/bmf
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/bmfconv
	${MKDIR} ${STAGEDIR}${PREFIX}/share/bmf
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${PREFIX}/share/bmf

.include <bsd.port.mk>
