# ex:ts=8
# New ports collection makefile for:	redland
# Date created:			Nov 22, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	redland
PORTVERSION=	1.0.2
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://librdf.org/dist/source/
MASTER_SITE_SUBDIR=	librdf

MAINTAINER=	chuck@pkix.net
COMMENT=	A high-level interface for RDF

LIB_DEPENDS=	raptor.2:${PORTSDIR}/textproc/raptor

# Berkeley DB is also needed, default to using 4.2 if not set otherwise.
WITH_BDB_VER?=	42
.if ${WITH_BDB_VER} == 3
LIB_DEPENDS+=	db3.3:${PORTSDIR}/databases/db3
.elif ${WITH_BDB_VER} == 4
LIB_DEPENDS+=	db4.0:${PORTSDIR}/databases/db4
.elif ${WITH_BDB_VER} == 41
LIB_DEPENDS+=	db41.1:${PORTSDIR}/databases/db41
.elif ${WITH_BDB_VER} == 42
LIB_DEPENDS+=	db-4.2.2:${PORTSDIR}/databases/db42
.elif ${WITH_BDB_VER} == 43
LIB_DEPENDS+=	db-4.3.0:${PORTSDIR}/databases/db43
.else
.error WITH_BDB_VER must be one of 3, 4, 41, 42 or 43
.endif

USE_GNOME=	gnomehack gnometarget lthack pkgconfig
USE_OPENSSL=	yes
USE_GETOPT_LONG=	yes
USE_GMAKE=	yes
USE_LIBTOOL_VER=	15
LIBTOOLFILES=	configure rasqal/configure

CPPFLAGS=	-I${LOCALBASE}/include/db${WITH_BDB_VER} -I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--with-raptor=system \
		--with-rasqal=internal \
		--with-threestore=no

# optional use of recent MySQL versions
.if defined(WANT_MYSQL_VER)
.if ${WANT_MYSQL_VER} < 323
	@${ECHO} "This port requires WANT_MYSQL_VER=323 or later to use MySQL."
.else
CONFIGURE_ARGS+=--with-mysql=yes
.endif
.endif

INSTALLS_SHLIB=	yes

MAN1=		rasqal-config.1 rdfproc.1 redland-config.1 \
		redland-db-upgrade.1 roqet.1
MAN3=		librasqal.3 redland.3

.include <bsd.port.mk>
