# Created by: Dan Caescu <daniel at freebsd.ro>
# $FreeBSD$

PORTNAME=	traff
PORTVERSION=	0.7
PORTREVISION=	1
CATEGORIES=	net net-mgmt
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	daniel@freebsd.ro
COMMENT=	Libpcab based fast traffic accounting program

BROKEN_FreeBSD_13=	ld: error: duplicate symbol: conf_file
BROKEN_FreeBSD_14=	ld: error: duplicate symbol: conf_file

BUILD_DEPENDS=	${LOCALBASE}/include/argp.h:devel/argp-standalone

USES=		gmake
USE_RC_SUBR=	traff
GNU_CONFIGURE=	yes

LIBS+=		-L${LOCALBASE}/lib -largp

OPTIONS_DEFINE=		MYSQL PGSQL
OPTIONS_DEFAULT=	MYSQL

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMYSQL}
USES+=		mysql
CPPFLAGS+=	-DwithMYSQL -I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib/mysql -lmysqlclient_r
CONFIGURE_ARGS+=--enable-mysql
.endif

.if ${PORT_OPTIONS:MPGSQL}
USES+=		pgsql
CPPFLAGS+=	-DwithPGSQL -I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib -lpq
CONFIGURE_ARGS+=--enable-postgresql
.endif

post-configure:
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" \
		${WRKSRC}/Makefile ${WRKSRC}/traff.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/traff ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/traff.conf ${STAGEDIR}${PREFIX}/etc/traff.conf.sample

.include <bsd.port.mk>
