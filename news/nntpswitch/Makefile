# New ports collection makefile for:	nntpswitch
# Date created:				Mar 18, 2004
# Whom:					clement
#
# $FreeBSD$
#

PORTNAME=	nntpswitch
PORTVERSION=	0.11
PORTREVISION=	1
CATEGORIES=	news
MASTER_SITES=	http://www.nntpswitch.org/download/

MAINTAINER=	clement@FreeBSD.org
COMMENT=	A NNTP content router

WRKSRC=		${WRKDIR}/${PORTNAME}
USE_GMAKE=	YES
USE_PERL5=	YES
INSTALLS_SHLIB=	YES

MAKE_ENV+=	PERL=${PERL} LIBS="${LDFLAGS}"
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

ETC_FILES=	access.conf servers.conf

ETC_DIR=	${PREFIX}/etc/${PORTNAME}
# dirty hack...
ALL_TARGET=	all

.if defined(WITH_MYSQL)
USE_MYSQL=	YES
ALL_TARGET+=	mysql
LDFLAGS+=	-L${LOCALBASE}/lib/mysql
PLIST_FILES+=	lib/${PORTNAME}/auth_mysql.so
.endif

.if defined(WITH_POSTGRESQL)
USE_PGSQL=	YES
ALL_TARGET+=	postgres
PLIST_FILES+=	lib/${PORTNAME}/auth_postgres.so
.endif

.if defined(WITH_FREERADIUS)
LIB_DEPENDS+=	radius:${PORTSDIR}/net/freeradius
ALL_TARGET+=	radius
PLIST_FILES+=	lib/${PORTNAME}/auth_radius.so lib/${PORTNAME}/acct_radius.so
.endif

.if defined(WITH_OPENLDAP)
USE_OPENLDAP=	YES
ALL_TARGET+=	ldap
PLIST_FILES+=	lib/${PORTNAME}/auth_ldap.so
.endif

.include <bsd.port.pre.mk>
.if ${OSVERSION} < 500029
BROKEN=		"${PORTNAME} requires atoll(3)"
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

.include <bsd.port.post.mk>
