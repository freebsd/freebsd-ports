# Created by: jrhett@netconsonance.com
# $FreeBSD$

PORTNAME=	cfengine
PORTVERSION=	3.9.0
# XXX Remember to update files/patch-configure.am with any new version number.
CATEGORIES=	sysutils
MASTER_SITES=	https://s3.amazonaws.com/cfengine-package-repos/tarballs/

MAINTAINER=	cy@FreeBSD.org
#		gjb@FreeBSD.org is also committer for this port
#		skreuzer@FreeBSD.org is also committer for this port
COMMENT=	Systems administration tool for networks

LICENSE=	GPLv3

CPE_VENDOR=	gnu

.if !defined(MASTERDIR)
PKGNAMESUFFIX=	39
.endif

FETCH_BEFORE_ARGS=	-o ${DISTDIR}/${DISTFILES}

CONFLICTS=	cfengine-[2-79]*

USE_RC_SUBR=	cf-execd cf-serverd cf-monitord

MAKE_JOBS_UNSAFE=	yes
USE_LDCONFIG=	yes
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
USES=		autoreconf:EXPLICIT_VERSION=${PORTVERSION} \
		cpe gmake libtool shebangfix
SHEBANG_FILES=	examples/remake_outputs.pl
CFLAGS+=	-Wno-return-type
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
# EXAMPLESDIR=	${PREFIX}/share/examples/cfengine3
DOCSDIR=	${PREFIX}/share/doc/cfengine
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
		liblmdb.so:databases/lmdb

OPTIONS_DEFINE=	PGSQL MYSQL LIBVIRT

PGSQL_USES=		pgsql
PGSQL_CONFIGURE_ON=	--with-postgresql=${LOCALBASE}

MYSQL_USE=		MYSQL=yes
MYSQL_CONFIGURE_ON=	--with-mysql=${LOCALBASE}
MYSQL_LIB_DEPENDS=		libmysqlclient.so:${_MYSQL_CLIENT}
MYSQL_LDFLAGS=		-L${LOCALBASE}/lib/mysql

LIBVIRT_CONFIGURE_ON=	--with-libvirt=${LOCALBASE}
LIBVIRT_LIB_DEPENDS+=		libvirt.so:devel/libvirt

.include <bsd.port.mk>
