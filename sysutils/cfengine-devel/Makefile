PORTNAME=	cfengine
PORTVERSION=	3.25.${CFENGINE_COMMIT_DATE}
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	sysutils
PKGNAMESUFFIX=	-devel
CFENGINE_HASH=		90e7ea198
LIBNTECH_HASH=		0908e5e
CFENGINE_COMMIT_DATE=	20250625

MAINTAINER=	cy@FreeBSD.org
COMMENT=	Systems administration tool for networks
WWW=		https://cfengine.com/

LICENSE=	GPLv3

USE_GITHUB=	yes
# GH_PROJECT=	core libntech:libntech
# GH_TAGNAME=	${CFENGINE_HASH} ${LIBNTECH_HASH}
GH_TUPLE=	cfengine:core:${CFENGINE_HASH} \
		cfengine:libntech:${LIBNTECH_HASH}:libntech/libntech
CPE_VENDOR=	gnu

CONFLICTS=	cfengine cfengine3[0-9] cfengine3[0-9][0-9]

USE_RC_SUBR=	cf-execd cf-serverd cf-monitord

MAKE_JOBS_UNSAFE=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USES=		autoreconf:build cpe gmake gnome libtool localbase shebangfix \
		ssl
USE_GNOME=	libxml2
SHEBANG_FILES=	examples/remake_outputs.pl
CFLAGS+=	-Wno-return-type -fcommon \
		-Wno-int-conversion \
		-Wno-implicit-function-declaration
# EXAMPLESDIR=	${PREFIX}/share/examples/cfengine3
DOCSDIR=	${PREFIX}/share/doc/cfengine
MAKE_ENV=	EXPLICIT_VERSION=${PORTVERSION}-${HASH}
EXPLICIT_VERSION=${PORTVERSION}-${HASH}
CONFIGURE_SCRIPT=	./autogen.sh
CONFIGURE_ENV=	EXPLICIT_VERSION=${PORTVERSION}-${HASH}
CONFIGURE_ARGS=	--docdir=${DOCSDIR} \
		--htmldir=${DOCSDIR}/html \
		--libexecdir=${PREFIX}/libexec \
		--libdir=${PREFIX}/libexec \
		--mandir=${PREFIX}/man \
		--with-workdir=/var/cfengine \
		--with-pcre2=${LOCALBASE} \
		--with-lmdb=${LOCALBASE} \
		--enable-fhs
INSTALL_TARGET=	install-strip

LIB_DEPENDS+=	libpcre.so:devel/pcre \
		libpcre2-posix.so:devel/pcre2 \
		liblmdb.so:databases/lmdb \
		libyaml.so:textproc/libyaml \
		libcurl.so:ftp/curl \
		librsync.so:net/librsync

OPTIONS_DEFINE=	PGSQL MYSQL LIBVIRT

PGSQL_USES=		pgsql
PGSQL_CONFIGURE_WITH=	postgresql=${LOCALBASE}

MYSQL_USES=		mysql
MYSQL_CONFIGURE_WITH=	mysql=${LOCALBASE}
MYSQL_LIB_DEPENDS=	libmysqlclient.so:${_MYSQL_CLIENT}
MYSQL_LDFLAGS=		-L${LOCALBASE}/lib/mysql

LIBVIRT_CONFIGURE_WITH=	libvirt=${LOCALBASE}
LIBVIRT_LIB_DEPENDS+=	libvirt.so:devel/libvirt

.include <bsd.port.mk>
