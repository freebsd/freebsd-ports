# Created by: jrhett@netconsonance.com
# $FreeBSD$

PORTNAME=	cfengine
PORTVERSION=	3.${CFENGINE_COMMIT_DATE}
CATEGORIES=	sysutils
PKGNAMESUFFIX=	-devel
CFENGINE_HASH=		ce24e40b7
LIBNTECH_HASH=		8eb4c31
CFENGINE_COMMIT_DATE=	2021.03.04

MAINTAINER=	cy@FreeBSD.org
#		gjb@FreeBSD.org is also committer for this port
#		skreuzer@FreeBSD.org is also committer for this port
COMMENT=	Systems administration tool for networks

LICENSE=	GPLv3

USE_GITHUB=	yes
# GH_PROJECT=	core libntech:libntech
# GH_TAGNAME=	${CFENGINE_HASH} ${LIBNTECH_HASH}
GH_TUPLE=	cfengine:core:${CFENGINE_HASH} \
		cfengine:libntech:${LIBNTECH_HASH}:libntech/libntech
CPE_VENDOR=	gnu

CONFLICTS=	cfengine-2* cfengine3[0-9]-* cfengine31[02-9]-* cfengine-3.*

CONFLICTS=	cfengine-[12-9]*

USE_RC_SUBR=	cf-execd cf-serverd cf-monitord

MAKE_JOBS_UNSAFE=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USES=		autoreconf:build cpe gmake gnome libtool localbase shebangfix \
		ssl
USE_GNOME=	libxml2
SHEBANG_FILES=	examples/remake_outputs.pl
CFLAGS+=	-Wno-return-type -fcommon
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
		--with-pcre=${LOCALBASE} \
		--with-lmdb=${LOCALBASE} \
		--enable-fhs
INSTALL_TARGET=	install-strip

LIB_DEPENDS+=	libpcre.so:devel/pcre \
		liblmdb.so:databases/lmdb \
		libyaml.so:textproc/libyaml \
		libcurl.so:ftp/curl

OPTIONS_DEFINE=	PGSQL MYSQL LIBVIRT

PGSQL_USES=		pgsql
PGSQL_CONFIGURE_WITH=	postgresql=${LOCALBASE}

MYSQL_USES=		mysql
MYSQL_BROKEN=		configure: error: MySQL client library exports symbols (EVP_CIPHER_CTX_init) clashing with OpenSSL.
MYSQL_CONFIGURE_WITH=	mysql=${LOCALBASE}
MYSQL_LIB_DEPENDS=	libmysqlclient.so:${_MYSQL_CLIENT}
MYSQL_LDFLAGS=		-L${LOCALBASE}/lib/mysql

LIBVIRT_CONFIGURE_WITH=	libvirt=${LOCALBASE}
LIBVIRT_LIB_DEPENDS+=	libvirt.so:devel/libvirt

.include <bsd.port.mk>
