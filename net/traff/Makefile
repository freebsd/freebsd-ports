# Created by: Dan Caescu <daniel at freebsd.ro>
# $FreeBSD$

PORTNAME=	traff
PORTVERSION=	0.7
CATEGORIES=	net net-mgmt
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	daniel@freebsd.ro
COMMENT=	Libpcab based fast traffic accounting program

BUILD_DEPENDS=	${LOCALBASE}/include/argp.h:${PORTSDIR}/devel/argp-standalone

USE_RC_SUBR=	traff
USES=		gmake
GNU_CONFIGURE=	yes

LIBS+=		-L${LOCALBASE}/lib -largp

OPTIONS_DEFINE=		MYSQL PGSQL
OPTIONS_DEFAULT=	MYSQL

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMYSQL}
USE_MYSQL=	yes
CPPFLAGS+=	-DwithMYSQL -I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib/mysql -lmysqlclient_r
CONFIGURE_ARGS+=--enable-mysql
.endif

.if ${PORT_OPTIONS:MPGSQL}
USE_PGSQL=	yes
CPPFLAGS+=	-DwithPGSQL -I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib -lpq
CONFIGURE_ARGS+=--enable-postgresql
.endif

post-configure:
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" \
		${WRKSRC}/Makefile ${WRKSRC}/traff.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/traff ${PREFIX}/sbin
.	if !exists(${PREFIX}/etc/traff.conf)
		${INSTALL_DATA} ${WRKSRC}/traff.conf ${PREFIX}/etc
.	endif
	${INSTALL_DATA} ${WRKSRC}/traff.conf ${PREFIX}/etc/traff.conf.default

.include <bsd.port.mk>
