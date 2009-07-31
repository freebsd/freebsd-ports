# ex:ts=8
# Ports collection makefile for:	GNUnet
# Date created:			Mar 23, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	gnunet
PORTVERSION=	0.6.6b
PORTREVISION=	8
CATEGORIES=	net-p2p ipv6
MASTER_SITES=	http://www.ovmj.org/GNUnet/download/ \
		${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	GNUnet-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An anonymous, distributed, reputation-based network

LIB_DEPENDS=	gmp.8:${PORTSDIR}/math/libgmp4

USE_AUTOTOOLS=	libltdl:15 libtool:15
GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gnometarget gtk20 lthack
USE_OPENSSL=	yes
USE_LDCONFIG=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include"
CONFIGURE_ARGS=	--disable-ltdl-install --with-crypto
LDFLAGS+=	-L${LOCALBASE}/lib

.if defined(WITH_GDBM)
LIB_DEPENDS+=		gdbm.3:${PORTSDIR}/databases/gdbm
PLIST_SUB+=		WITH_GDBM=""
.else
CONFIGURE_ARGS+=	--without-gdbm
PLIST_SUB+=		WITH_GDBM="@comment "
.endif

.if defined(WITH_MYSQL)
USE_MYSQL=	yes
CONFIGURE_ARGS+=	--with-mysql
.else
CONFIGURE_ARGS+=	--without-mysql
.endif

.if defined(WITH_TDB)
LIB_DEPENDS+=		tdb.1:${PORTSDIR}/databases/tdb
PLIST_SUB+=		WITH_TDB=""
.else
CONFIGURE_ARGS+=	--without-tdb
PLIST_SUB+=		WITH_TDB="@comment "
.endif

.if defined(WITH_BDB3)
LIB_DEPENDS+=		db3:${PORTSDIR}/databases/db3
CONFIGURE_ARGS+=	--with-bdb=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--without-bdb
.endif

.if defined(WITH_SQLITE)
LIB_DEPENDS+=		sqlite3.8:${PORTSDIR}/databases/sqlite3
CONFIGURE_ARGS+=	--with-sqlite
PLIST_SUB+=		WITH_SQLITE=""
.else
CONFIGURE_ARGS+=	--without-sqlite
PLIST_SUB+=		WITH_SQLITE="@comment "
.endif

.if defined(WITH_IPV6)
PKGNAMESUFFIX=		-ipv6
CONFIGURE_ARGS+=	--enable-ipv6
PLIST_SUB+=		WITH_IPV6=""
.else
PLIST_SUB+=		WITH_IPV6="@comment "
.endif

.if defined(WITH_GUILE)
LIB_DEPENDS+=		guile.20:${PORTSDIR}/lang/guile
CONFIGURE_ARGS+=	--enable-guile
MAN1+=			gnunet-download-manager.1
PLIST_SUB+=		WITH_GUILE=""
.else
CONFIGURE_ARGS+=	--disable-guile
PLIST_SUB+=		WITH_GUILE="@comment "
.endif

MAN1=		gnunet-chat.1 gnunet-check.1 gnunet-convert.1 \
		gnunet-delete.1 gnunet-directory.1 \
		gnunet-download.1 gnunet-gtk.1 gnunet-insert.1 \
		gnunet-peer-info.1 gnunet-pseudonym.1 \
		gnunet-search.1 gnunet-stats.1 gnunet-tbench.1 \
		gnunet-testbed.1 gnunet-tracekit.1 gnunet-transport-check.1 \
		gnunet-update.1 gnunetd.1
MAN5=		gnunet.conf.5

.include <bsd.port.pre.mk>

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "You can build GNUnet with the following options:"
	@${ECHO_MSG} "		WITH_MYSQL=yes		Turn on MySQL support"
	@${ECHO_MSG} "		WITH_TDB=yes		Turn on TDB support"
	@${ECHO_MSG} "		WITH_BDB3=yes		Turn on Berkely DB library support"
	@${ECHO_MSG} "		WITH_GDBM=yes		Turn on GNU dbm support"
	@${ECHO_MSG} "		WITH_SQLITE=yes		Turn on sqlite support"
	@${ECHO_MSG} "		WITH_IPV6=yes		Turn on to enable IPv6 support"
	@${ECHO_MSG} ""

post-patch:
	@${FIND} ${WRKSRC} -name configure | ${XARGS} \
	${REINPLACE_CMD} -e \
		's|-pthread [\$$]CFLAGS|${PTHREAD_CFLAGS} \$$CFLAGS|g ; \
		 s|-lpthread|${PTHREAD_LIBS}|g'
	${REINPLACE_CMD} -e \
		's|^#include <values.h>|#include <limits.h>|g' \
		${WRKSRC}/src/applications/afs/module/manager.c
	${REINPLACE_CMD} -e \
		's|%%PREFIX%%|${PREFIX}|g' \
		${WRKSRC}/src/include/gnunet_util.h

post-install:
	${INSTALL_DATA}	${WRKSRC}/contrib/gnunet.root ${PREFIX}/etc/gnunet.conf-dist
.ifndef(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA}	${WRKSRC}/contrib/gnunet.user ${DOCSDIR}
	${INSTALL_DATA}	${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA}	${WRKSRC}/ChangeLog ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
