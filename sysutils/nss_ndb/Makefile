PORTNAME=		nss_ndb
DISTVERSIONPREFIX=	v
DISTVERSION=		1.0.24
CATEGORIES=		sysutils security

MAINTAINER=		pen@lysator.liu.se
COMMENT=		BerkeleyDB-based nsswitch backend for passwd & groups

LICENSE=		BSD3CLAUSE
LICENSE_FILE=		${WRKSRC}/LICENSE

OPTIONS_DEFINE=		CFG VAR REALM WRKGRP

CFG_DESC=		Enable configuration file
CFG_CONFIGURE_ON=	--with-config-file
CFG_PLIST_FILES+=	"@sample etc/nss_ndb.conf.sample"

VAR_DESC=		Enable configuration variable
VAR_CONFIGURE_ON=	--with-config-var

REALM_DESC=		Enable realm stripping
REALM_CONFIGURE_ON=	--with-realm

WRKGRP_DESC=		Enable workgroup stripping
WRKGRP_CONFIGURE_ON=	--with-workgroup

OPTIONS_SINGLE=		BDB
OPTIONS_SINGLE_BDB=	DB0 DB18
OPTIONS_DEFAULT=	DB0

DB0_DESC=		Use the libc version of Berkeley DB (old)
DB0_CONFIGURE_ON=	--without-db

DB18_DESC=		Build with Berkeley DB v18 library
DB18_USES+=		localbase
DB18_USE_LDCONFIG+=	yes
DB18_LIB_DEPENDS=	libdb-18.so:databases/db18
DB18_CONFIGURE_ON=	--with-db=18

USE_GITHUB=		yes
GH_ACCOUNT=		ptrrkssn

GNU_CONFIGURE=		yes

PLIST_FILES=		lib/nss_ndb.so.1 \
			lib/nss_ndb.so.1.0.24 \
			sbin/makendb sbin/nsstest \
			man/man5/nss_ndb.conf.5.gz \
			man/man8/makendb.8.gz \
			man/man8/nsstest.8.gz \
			man/man8/nss_ndb.8.gz \
			share/examples/nss_ndb/ndbsync \
			share/examples/nss_ndb/nss_ndb.conf \

do-install-CFG-on:
	${INSTALL_DATA} ${WRKSRC}/nss_ndb.conf ${STAGEDIR}${PREFIX}/etc/nss_ndb.conf.sample

.include <bsd.port.mk>
