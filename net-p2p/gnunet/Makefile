# ex:ts=8
# Ports collection makefile for:	GNUnet
# Date created:			Mar 23, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	gnunet
PORTVERSION=	0.8.1b
PORTREVISION=	11
CATEGORIES=	net-p2p ipv6
MASTER_SITES=	GNU \
		http://gnunet.org/download/
DISTNAME=	GNUnet-${PORTVERSION}

MAINTAINER=	bf@FreeBSD.org
COMMENT=	An anonymous, distributed, reputation-based network

LIB_DEPENDS=	adns.1:${PORTSDIR}/dns/adns \
		cares.2:${PORTSDIR}/dns/c-ares \
		curl.6:${PORTSDIR}/ftp/curl \
		guile.21:${PORTSDIR}/lang/guile \
		esmtp.6:${PORTSDIR}/mail/libesmtp \
		gmp.10:${PORTSDIR}/math/gmp \
		gcrypt.18:${PORTSDIR}/security/libgcrypt \
		extractor.3:${PORTSDIR}/textproc/libextractor \
		microhttpd.23:${PORTSDIR}/www/libmicrohttpd

BROKEN=		does not configure

OPTIONS=	MYSQL	"Enable MySQL support"		on \
		PGSQL	"Enable PostgreSQL support"	off \
		SQLITE	"Enable SQLite support"		off

USE_GNOME=	gnomehack libglade2
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	libltdl libtool
CONFIGURE_ARGS=	--with-dialog=no \
		--with-cdialog=no \
		--with-qt=no \
		--with-daemon-home-dir=${DBDIR} \
		--with-daemon-config-dir=${PREFIX}/etc
USE_LDCONFIG=	yes

PLIST_SUB=	DBDIR="${DBDIR}"

MAN1=		gnunet-auto-share.1 gnunet-chat.1 gnunet-directory.1 \
		gnunet-download.1 gnunet-insert.1 gnunet-peer-info.1 \
		gnunet-pseudonym.1 gnunet-search.1 gnunet-setup.1 \
		gnunet-stats.1 gnunet-tbench.1 gnunet-testbed.1 \
		gnunet-tracekit.1 gnunet-transport-check.1 gnunet-unindex.1 \
		gnunet-update.1 gnunet-vpn.1 gnunetd.1
MAN5=		gnunet.conf.5 gnunetd.conf.5

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

DBDIR=		/var/db/${PORTNAME}

.include <bsd.port.pre.mk>

.if defined(WITHOUT_MYSQL)
CONFIGURE_ARGS+=	--without-mysql
PLIST_SUB+=		MYSQL="@comment "
.else
USE_MYSQL=		yes
CONFIGURE_ARGS+=	--with-mysql=${LOCALBASE}
PLIST_SUB+=		MYSQL=""
.endif

.if defined(WITH_PGSQL)
USE_PGSQL=		yes
CONFIGURE_ARGS+=	--with-postgres=${LOCALBASE}
PLIST_SUB+=		PGSQL=""
.else

CONFIGURE_ARGS+=	--without-postgres
PLIST_SUB+=		PGSQL="@comment "
.endif

.if defined(WITH_SQLITE)
USE_SQLITE=		yes
CONFIGURE_ARGS+=	--with-sqlite=${LOCALBASE}
PLIST_SUB+=		SQLITE=""
.else
CONFIGURE_ARGS+=	--without-sqlite
PLIST_SUB+=		SQLITE="@comment "
.endif

post-patch:
.for i in configure src/applications/sqstore_postgres/postgres.c
	@${REINPLACE_CMD} -e 's|postgresql/||g' ${WRKSRC}/${i}
.endfor
.for i in src/util/crypto/Makefile.in
	@${REINPLACE_CMD} -e 's|)[[:space:]]-O3|)|g' ${WRKSRC}/${i}
.endfor

post-install:
	@${MKDIR} ${DBDIR}
.for i in gnunet.conf gnunetd.conf
	${INSTALL_DATA}	${WRKSRC}/contrib/${i} ${PREFIX}/etc/${i}-dist
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in AUTHORS ChangeLog HACKING README UPDATING
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/contrib/*.cgi ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/contrib/*.php ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/contrib/*.sh ${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>
