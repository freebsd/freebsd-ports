# ex:ts=8
# Ports collection makefile for:	GNUnet
# Date created:			Mar 23, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	gnunet
PORTVERSION=	0.6.1
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.ovmj.org/GNUnet/download/ \
		${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	GNUnet-${PORTVERSION}

MAINTAINER=	krion@FreeBSD.org
COMMENT=	An anonymous, distributed, reputation-based network

LIB_DEPENDS=	ltdl.4:${PORTSDIR}/devel/libltdl

USE_GETTEXT=	yes
USE_SIZE=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
USE_BZIP2=	yes
USE_OPENSSL=	yes
USE_GNOME=	gtk12
USE_GETOPT_LONG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include"
CONFIGURE_ARGS=	--disable-ltdl-install
LDFLAGS+=	-L${LOCALBASE}/lib

.if defined(WITH_GDBM)
LIB_DEPENDS+=	gdbm.3:${PORTSDIR}/databases/gdbm
PLIST_SUB+=	WITH_GDBM=""
.else
CONFIGURE_ARGS+=	--without-gdbm
PLIST_SUB+=	WITH_GDBM="@comment "
.endif

.if defined(WITH_MYSQL)
USE_MYSQL=	yes
WANT_MYSQL_VER=	323
CONFIGURE_ARGS+=	--with-mysql
.else
CONFIGURE_ARGS+=	--without-mysql
.endif

.if defined(WITH_TDB)
LIB_DEPENDS+=	tdb.1:${PORTSDIR}/databases/tdb
PLIST_SUB+=	WITH_TDB=""
.else
CONFIGURE_ARGS+=	--without-tdb
PLIST_SUB+=	WITH_TDB="@comment "
.endif

.if defined(WITH_BDB3)
LIB_DEPENDS+=	db3:${PORTSDIR}/databases/db3
CONFIGURE_ARGS+=	--with-bdb=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--without-bdb
.endif

.if defined(WITH_IPV6)
PKGNAMESUFFIX=	-ipv6
CONFIGURE_ARGS+=	--enable-ipv6
PLIST_SUB+=	WITH_IPV6=""
.else
PLIST_SUB+=	WITH_IPV6="@comment "
.endif

MAN1=		gnunet-chat.1 gnunet-check.1 gnunet-convert.1 \
		gnunet-delete.1 gnunet-directory-emptydb.1 gnunet-directory-listdb.1 \
		gnunet-directory-print.1 gnunet-download.1 \
		gnunet-gtk.1 gnunet-insert.1 gnunet-peer-info.1 \
		gnunet-pseudonym-create.1 gnunet-pseudonym-delete.1 \
		gnunet-pseudonym-list.1 gnunet-search-sblock.1 \
		gnunet-search.1 gnunet-stats.1 gnunet-tbench.1 \
		gnunet-testbed.1 gnunet-tracekit.1 gnunet-transport-check.1 \
		gnunetd.1
MAN5=		gnunet.conf.5

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "You can build GNUnet with the following options:"
	@${ECHO_MSG} "		WITH_MYSQL=yes		Turn on MySQL support"
	@${ECHO_MSG} "		WITH_TDB=yes		Turn on TDB support"
	@${ECHO_MSG} "		WITH_BDB41=yes		Turn on Berkely DB library support"
	@${ECHO_MSG} "		WITH_GDBM=yes		Turn on GNU dbm support"
	@${ECHO_MSG} "		WITH_IPV6=yes		Turn on to enable IPv6 support"
	@${ECHO_MSG} ""

post-patch:
	@{FIND} ${WRKSRC} -name configure | ${XARGS} \
	@${REINPLACE_CMD} -e \
		's|-pthread [\$$]CFLAGS|${PTHREAD_CFLAGS} \$$CFLAGS|g ; \
		 s|-lpthread|${PTHREAD_LIBS}|g'

.include <bsd.port.mk>
