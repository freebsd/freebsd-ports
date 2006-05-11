# New ports collection makefile for:	traff
# Date created:				2005-09-26
# Whom:					Dan Caescu <daniel at freebsd.ro>
#
# $FreeBSD$
#

PORTNAME=	traff
PORTVERSION=	0.6.1
CATEGORIES=	net net-mgmt
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	traff
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	daniel@freebsd.ro
COMMENT=	Libpcab based fast traffic accounting program

USE_RC_SUBR=	traff.sh
USE_GMAKE=	yes

CFLAGS+=	${PTHREAD_CFLAGS}
LFLAGS=		${PTHREAD_LIBS}

OPTIONS=	MYSQL	"Enable MYSQL storage" 	on \
		PGSQL	"Enable PGSQL storage"	off

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_MYSQL)
USE_MYSQL=	yes
CFLAGS+=	-DwithMYSQL -I${LOCALBASE}/include
LFLAGS+=	-L${LOCALBASE}/lib/mysql -lmysqlclient_r
.endif

.if defined(WITH_PGSQL)
USE_PGSQL=	yes
CFLAGS+=	-DwithPGSQL -I${LOCALBASE}/include
LFLAGS+=	-L${LOCALBASE}/lib -lpq
.endif

MAKE_ARGS+=	EXTRA_LIBS="${LFLAGS}"

post-patch:
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" \
		${WRKSRC}/Makefile ${WRKSRC}/traff.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/traff ${PREFIX}/sbin
.	if !exists(${PREFIX}/etc/traff.conf)
		${INSTALL_DATA} ${WRKSRC}/traff.conf ${PREFIX}/etc
.	endif
	${INSTALL_DATA} ${WRKSRC}/traff.conf ${PREFIX}/etc/traff.conf.default

.include <bsd.port.post.mk>
