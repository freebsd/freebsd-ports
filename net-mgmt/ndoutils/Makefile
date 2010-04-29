# New ports collection makefile for:	ndoutils
# Date created:				14 February 2008
# Whom:					Philip M. Gollucci <pgollucci@p6m7g8.com>
#
# $FreeBSD$
#

PORTNAME=	ndoutils
PORTVERSION=	1.4b8
PORTREVISION=	2
CATEGORIES=	net-mgmt
MASTER_SITES=	SF/nagios/${PORTNAME}-1.x/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Keep Nagios perfdata in MySQL or Postgresql database

RUN_DEPENDS=	${LOCALBASE}/bin/nagios:${PORTSDIR}/net-mgmt/nagios

OPTIONS=	MYSQL	"MySQL Backend"		on \
			PGSQL	"Postgresql Backend"	off

MAKE_JOBS_UNSAFE=	yes

GNU_CONFIGURE=	yes
CFLAGS+=	-I${LOCALBASE}/include -fPIC
CONFIGURE_ARGS+=	--sysconfdir=${PREFIX}/etc/ndoutils

CFG_FILES=	misccommands ndo2db ndomod

USE_RC_SUBR=	ndo2db
SUB_FILES=	pkg-message

.include <bsd.port.options.mk>
.if !defined(WITHOUT_MYSQL)
USE_MYSQL=yes
CONFIGURE_ARGS+=	--enable-mysql \
					--with-mysql-lib=${LOCALBASE}/lib/mysql \
					--with-mysql-inc=${LOCALBASE}/include
.else
CONFIGURE_ARGS+=	--disable-mysql
.endif

.if defined(WITH_PGSQL)
USE_PGSQL=yes
CONFIGURE_ARGS+=	--enable-pgsql \
					--with-pgsql-lib=${LOCALBASE}/lib/pgsql \
					--with-pgsql-inc=${LOCALBASE}/include/pgsql
.else
CONFIGURE_ARGS+=	--disable-pgsql
.endif

.if defined(WITHOUT_MYSQL) && defined(WITHOUT_PGSQL)
IGNORE=	you should define at least 1 of WITH_MYSQL or WITH_PGSQL, WITH_MYSQL=yes is the default
.endif

.if !defined(NOPORTDOCS)
PLIST_SUB+=	PORTDOCS=""
.else
PLIST_SUB+=	PORTDOCS="@comment "
.endif

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/src/ndo2db-3x ${PREFIX}/bin/
	@${INSTALL_PROGRAM} ${WRKSRC}/src/ndomod-3x.o ${PREFIX}/bin/
	@${INSTALL_PROGRAM} ${WRKSRC}/src/file2sock ${PREFIX}/bin/
	@${INSTALL_PROGRAM} ${WRKSRC}/src/log2ndo ${PREFIX}/bin/
	@${INSTALL_PROGRAM} ${WRKSRC}/src/sockdebug ${PREFIX}/bin/
	@(cd ${WRKSRC}/db && ${COPYTREE_SHARE} \* ${DATADIR}/)
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@(cd ${WRKSRC}/docs && ${COPYTREE_SHARE} \* ${DOCSDIR}/)
.endif
	@for i in ${CFG_FILES}; do \
		${INSTALL_DATA} ${WRKSRC}/config/$${i}.cfg ${PREFIX}/etc/nagios/$${i}.cfg-sample; \
	done
	@${INSTALL_DATA} ${WRKSRC}/config/nagios.cfg ${PREFIX}/etc/nagios/ndoutils.cfg-sample
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
