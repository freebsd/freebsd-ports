# Created by: jrhett@netconsonance.com
# $FreeBSD$

PORTNAME=	cfengine
PORTVERSION=	3.6.2rc
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	sysutils
MASTER_SITES=	https://s3.amazonaws.com/cfengine.package-repos/tarballs/

MAINTAINER=	cy@FreeBSD.org
#		gjb@FreeBSD.org is also committer for this port
COMMENT=	Systems administration tool for networks

LICENSE=	GPLv3

.if !defined(MASTERDIR)
PKGNAMESUFFIX=	36-rc
LATEST_LINK=	cfengine36-rc
.endif

FETCH_BEFORE_ARGS=	-o ${DISTDIR}/${DISTFILES}

CONFLICTS=	cfengine-[234]*

USE_RC_SUBR=	cf-execd cf-serverd cf-monitord

MAKE_JOBS_UNSAFE=	yes
USE_LDCONFIG=	yes
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
USES=		gmake libtool
USE_AUTOTOOLS=	autoconf:env automake:env libtoolize:env
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

LIB_DEPENDS+=	libpcre.so:${PORTSDIR}/devel/pcre \
		liblmdb.so:${PORTSDIR}/databases/lmdb

OPTIONS_DEFINE=	PGSQL MYSQL LIBVIRT

PGSQL_USES=		pgsql
PGSQL_CONFIGURE_ON=	--with-postgresql=${LOCALBASE}

MYSQL_USE=		MYSQL=yes
MYSQL_CONFIGURE_ON=	--with-mysql=${LOCALBASE}
MYSQL_LIB_DEPENDS=		libmysqlclient.so:${PORTSDIR}/${_MYSQL_CLIENT}
MYSQL_LDFLAGS=		-L${LOCALBASE}/lib/mysql

LIBVIRT_CONFIGURE_ON=	--with-libvirt=${LOCALBASE}
LIBVIRT_LIB_DEPENDS+=		libvirt.so:${PORTSDIR}/devel/libvirt

pre-configure:
	@cd ${WRKSRC}; autoreconf -Wno-portability --force --install -I m4

.include <bsd.port.mk>
