# New ports collection makefile for:	nntpswitch
# Date created:				Mar 18, 2004
# Whom:					clement
#
# $FreeBSD$
#

PORTNAME=	nntpswitch
PORTVERSION=	0.10
CATEGORIES=	news
MASTER_SITES=	http://www.nntpswitch.org/download/

MAINTAINER=	clement@FreeBSD.org
COMMENT=	A NNTP content router

WRKSRC=		${WRKDIR}/${PORTNAME}
USE_GMAKE=	YES
USE_PERL5=	YES
INSTALLS_SHLIB=	YES
USE_REINPLACE=	YES

MAKE_ENV+=	PERL=${PERL} LIBS="${LDFLAGS}"
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

ETC_FILES=	access.conf auth.conf overview.fmt profiles.conf \
		servers.conf passwd

ETC_DIR=	${PREFIX}/etc/${PORTNAME}
# dirty hack...
ALL_TARGET=	all

.if defined(WITH_MYSQL)
USE_MYSQL=	YES
ALL_TARGET+=	mysql
LDFLAGS+=	-L${LOCALBASE}/lib/mysql
PLIST_FILES+=	lib/libauth_mysql.so
.endif

.if defined(WITH_POSTGRESQL)
USE_PGSQL=	YES
ALL_TARGET+=	postgres
PLIST_FILES+=	lib/libauth_postgres.so
.endif

.if defined(WITH_FREERADIUS)
LIB_DEPENDS+=	radius:${PORTSDIR}/net/freeradius
ALL_TARGET+=	radius
PLIST_FILES+=	lib/libauth_radius.so lib/libacct_radius.so
.endif

do-configure:
	@${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},' ${WRKSRC}/nntpswitch.conf.in

post-install:
	${MKDIR} ${PREFIX}/etc/${PORTNAME}
.for FILE in ${ETC_FILES}
	${INSTALL_DATA} ${WRKSRC}/etc/${FILE} ${ETC_DIR}/${FILE}-dist
.endfor
	${INSTALL_DATA} ${WRKSRC}/nntpswitch.conf-dist ${ETC_DIR}/
	${INSTALL_SCRIPT} ${FILESDIR}/nntpswitch.sh ${PREFIX}/etc/rc.d/nntpswitch.sh-dist
.include <bsd.port.mk>
