# Created by: jrhett@netconsonance.com
# $FreeBSD$

PORTNAME=	cfengine
PORTVERSION=	3.10.5
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	https://s3.amazonaws.com/cfengine-package-repos/tarballs/

MAINTAINER=	cy@FreeBSD.org
#		gjb@FreeBSD.org is also committer for this port
#		skreuzer@FreeBSD.org is also committer for this port
COMMENT=	Systems administration tool for networks

LICENSE=	GPLv3

CPE_VENDOR=	gnu

DEPRECATED=		OpenSSL 1.1.X is not supported.
EXPIRATION_DATE=	2021-09-30

CONFLICTS=	cfengine3[0-9]-* cfengine31[1-9]-*
.if !defined(MASTERDIR)
PKGNAMESUFFIX=	310
CONFLICTS+=	cfengine-3.*
.endif

FETCH_BEFORE_ARGS=	-o ${DISTDIR}/${DISTFILES}

USE_RC_SUBR=	cf-execd cf-serverd cf-monitord

MAKE_JOBS_UNSAFE=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USES=		autoreconf \
		cpe gmake localbase libtool shebangfix ssl
USE_GNOME=	libxml2
SHEBANG_FILES=	examples/remake_outputs.pl
CFLAGS+=	-Wno-return-type
# EXAMPLESDIR=	${PREFIX}/share/examples/cfengine3
DOCSDIR=	${PREFIX}/share/doc/cfengine
MAKE_ENV=	EXPLICIT_VERSION=${PORTVERSION}
CONFIGURE_ENV=	EXPLICIT_VERSION=${PORTVERSION}
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
PGSQL_CONFIGURE_WITH=	--with-postgresql=${LOCALBASE}
PGSQL_CONFIGURE_OFF=	--without-postgresql

MYSQL_USES=		mysql
MYSQL_BROKEN=		configure: error: MySQL client library exports symbols (EVP_CIPHER_CTX_init) clashing with OpenSSL.
MYSQL_CONFIGURE_WITH=	--with-mysql=${LOCALBASE}
MYSQL_CONFIGURE_OFF=	--without-mysql
MYSQL_LIB_DEPENDS=	libmysqlclient.so:${_MYSQL_CLIENT}
MYSQL_LDFLAGS=		-L${LOCALBASE}/lib/mysql

LIBVIRT_CONFIGURE_WITH=	--with-libvirt=${LOCALBASE}
LIBVIRT_LIB_DEPENDS+=	libvirt.so:devel/libvirt

.include <bsd.port.pre.mk>

.if ${OPSYS} == "FreeBSD" && ${OSVERSION} >= 1200085
.if ${SSL_DEFAULT} != "openssl"
BROKEN_FreeBSD_12=	fails to build with openssl111, install security/openssl
BROKEN_FreeBSD_13=	fails to build with openssl111, install security/openssl
.endif
.endif

.include <bsd.port.post.mk>
