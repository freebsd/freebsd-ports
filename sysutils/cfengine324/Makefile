PORTNAME=	cfengine
DISTVERSION=	3.24.1
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	https://s3.amazonaws.com/cfengine-package-repos/tarballs/
DISTNAME=	${PORTNAME}-community-${DISTVERSION}

MAINTAINER=	cy@FreeBSD.org
COMMENT=	Systems administration tool for networks
WWW=		https://cfengine.com/

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}

LICENSE=	GPLv3

CPE_VENDOR=	gnu

CONFLICTS=	cfengine cfengine3[0-9] cfengine3[0-9][0-9]
.if !defined(MASTERDIR)
PKGNAMESUFFIX=	324
.endif

FETCH_BEFORE_ARGS=	-o ${DISTDIR}/${DISTFILES}

USE_RC_SUBR=	cf-execd cf-serverd cf-monitord

MAKE_JOBS_UNSAFE=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USES=		autoreconf cpe gmake gnome libtool localbase shebangfix ssl
USE_GNOME=	libxml2
SHEBANG_FILES=	examples/remake_outputs.pl
CFLAGS+=	-Wno-return-type -fcommon
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
		--with-pcre2=${LOCALBASE} \
		--with-lmdb=${LOCALBASE} \
		--enable-fhs
INSTALL_TARGET=	install-strip

LIB_DEPENDS+=	libpcre.so:devel/pcre \
		libpcre2-posix.so:devel/pcre2 \
		liblmdb.so:databases/lmdb \
		libyaml.so:textproc/libyaml \
		libcurl.so:ftp/curl

OPTIONS_DEFINE=	PGSQL MYSQL LIBVIRT

PGSQL_USES=		pgsql
PGSQL_CONFIGURE_WITH=	--with-postgresql=${LOCALBASE}
PGSQL_CONFIGURE_OFF=	--without-postgresql

MYSQL_USES=		mysql
MYSQL_CONFIGURE_WITH=	--with-mysql=${LOCALBASE}
MYSQL_CONFIGURE_OFF=	--without-mysql
MYSQL_LIB_DEPENDS=	libmysqlclient.so:${_MYSQL_CLIENT}
MYSQL_LDFLAGS=		-L${LOCALBASE}/lib/mysql

LIBVIRT_CONFIGURE_WITH=	--with-libvirt=${LOCALBASE}
LIBVIRT_LIB_DEPENDS+=	libvirt.so:devel/libvirt

.include <bsd.port.mk>
