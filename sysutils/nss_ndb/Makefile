# $FreeBSD$

PORTNAME=		nss_ndb
DISTVERSIONPREFIX=	v
DISTVERSION=		1.0.23
CATEGORIES=		sysutils security

MAINTAINER=		pen@lysator.liu.se
COMMENT=		BerkeleyDB-based nsswitch backend for passwd & groups

LICENSE=		BSD3CLAUSE
LICENSE_FILE=		${WRKSRC}/LICENSE

OPTIONS_DEFINE=		CFG VAR REALM WRKGRP

CFG_DESC=		Enable configuration file
CFG_CONFIGURE_ON=	--with-config-file
CFG_PLIST_FILES+=	etc/nss_ndb.conf

VAR_DESC=		Enable configuration variable
VAR_CONFIGURE_ON=	--with-config-var

REALM_DESC=		Enable realm stripping
REALM_CONFIGURE_ON=	--with-realm

WRKGRP_DESC=		Enable workgroup stripping
WRKGRP_CONFIGURE_ON=	--with-workgroup

OPTIONS_SINGLE=		BDB
OPTIONS_SINGLE_BDB=	DB0 DB6 DB5 DB4
OPTIONS_DEFAULT=	DB0

DB0_DESC=		Use old libc version of Berkeley DB
DB0_CONFIGURE_ON=	--without-db

DB6_DESC=		Build with Berkeley DB v6 library
DB6_USES+=		localbase
DB6_USE_LDCONFIG+=	yes
DB6_LIB_DEPENDS=	libdb-6.so:databases/db6
DB6_CONFIGURE_ON=	--with-db=6

DB5_DESC=		Build with Berkeley DB v5 library
DB5_USES+=		localbase
DB5_USE_LDCONFIG+=	yes
DB5_LIB_DEPENDS=	libdb-5.so:databases/db5
DB5_CONFIGURE_ON=	--with-db=5

DB4_DESC=		Build with Berkeley DB v4.8 library
DB4_USES+=		localbase
DB4_USE_LDCONFIG+=	yes
DB4_LIB_DEPENDS=	libdb-4.8.so:databases/db48
DB4_CONFIGURE_ON=	--with-db=4

USE_GITHUB=		yes
GH_ACCOUNT=		ptrrkssn

GNU_CONFIGURE=		yes

PLIST_FILES=		lib/nss_ndb.so.1 \
			lib/nss_ndb.so.1.0.23 \
			sbin/makendb sbin/nsstest \
			man/man5/nss_ndb.conf.5.gz \
			man/man8/makendb.8.gz \
			man/man8/nsstest.8.gz \
			man/man8/nss_ndb.8.gz \
			share/examples/nss_ndb/ndbsync \
			share/examples/nss_ndb/nss_ndb.conf \

.include <bsd.port.mk>
