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
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

CFLAGS+=	${PTHREAD_CFLAGS} -L${LOCALBASE}/lib
LFLAGS=		${PTHREAD_LIBS}
CONFIGURE_ENV+=	"LIBS=-largp"

OPTIONS_DEFINE=		MYSQL PGSQL
OPTIONS_DEFAULT=	MYSQL

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMYSQL}
USE_MYSQL=	yes
CFLAGS+=	-DwithMYSQL -I${LOCALBASE}/include -L${LOCALBASE}/lib/mysql
LFLAGS+=	-L${LOCALBASE}/lib/mysql -lmysqlclient_r
CONFIGURE_ARGS+=--enable-mysql
.endif

.if ${PORT_OPTIONS:MPGSQL}
USE_PGSQL=	yes
CFLAGS+=	-DwithPGSQL -I${LOCALBASE}/include
LFLAGS+=	-L${LOCALBASE}/lib -lpq
CONFIGURE_ARGS+=--enable-postgresql
.endif

MAKE_ARGS+=	EXTRA_LIBS="${LFLAGS}"

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
