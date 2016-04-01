# Created by: jrhett@netconsonance.com
# $FreeBSD$

PORTNAME=	cfengine
PORTVERSION=	3.5.3
PORTREVISION=	10
CATEGORIES=	sysutils
MASTER_SITES=	https://s3.amazonaws.com/cfengine.package-repos/tarballs/

MAINTAINER=	cy@FreeBSD.org
#		gjb@FreeBSD.org is also committer for this port
#		skreuzer@FreeBSD.org is also committer for this port
COMMENT=	Systems administration tool for networks

LICENSE=	GPLv3

CPE_VENDOR=	gnu

LIB_DEPENDS=	libpcre.so:devel/pcre

.if !defined(MASTERDIR)
PKGNAMESUFFIX=	35
.endif

FETCH_BEFORE_ARGS=	-o ${DISTDIR}/${DISTFILES}

CONFLICTS=	cfengine-[2346-9]*

USE_RC_SUBR=	cf-execd cf-serverd cf-monitord

USES=		cpe gmake libtool
USE_LDCONFIG=	yes
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
CFLAGS+=	-Wno-return-type
# EXAMPLESDIR=	${PREFIX}/share/examples/cfengine3
DOCSDIR=	${PREFIX}/share/doc/cfengine
CONFIGURE_ARGS=	--docdir=${DOCSDIR} \
		--htmldir=${DOCSDIR}/html \
		--libexecdir=${PREFIX}/libexec \
		--libdir=${PREFIX}/libexec \
		--mandir=${PREFIX}/man \
		--with-workdir=/var/cfengine \
		--with-pcre=${LOCALBASE} \
		--enable-fhs
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	PGSQL MYSQL LIBVIRT
OPTIONS_SINGLE=	DB
OPTIONS_SINGLE_DB=	TOKYOCABINET QDBM
TOKYOCABINET_DESC=	Enable TokyoCabinet database backend
QDBM_DESC=	Enable QDBM database backend
OPTIONS_DEFAULT=TOKYOCABINET

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MTOKYOCABINET}
CONFIGURE_ARGS+=	--with-tokyocabinet=${LOCALBASE}
LIB_DEPENDS+=	libtokyocabinet.so:databases/tokyocabinet
.endif

.if ${PORT_OPTIONS:MQDBM}
CONFIGURE_ARGS+=	--with-qdbm=${LOCALBASE}
LIB_DEPENDS+=	libqdbm.so:databases/qdbm
.endif

.if ${PORT_OPTIONS:MPGSQL}
USES+=			pgsql
CONFIGURE_ARGS+=	--with-postgresql=${LOCALBASE}
.endif

.if ${PORT_OPTIONS:MMYSQL}
USE_MYSQL=		yes
CONFIGURE_ARGS+=	--with-mysql=${LOCALBASE}
LIB_DEPENDS+=		libmysqlclient.so:${_MYSQL_CLIENT}
LDFLAGS+=		-L${LOCALBASE}/lib/mysql
.endif

.if ${PORT_OPTIONS:MLIBVIRT}
CONFIGURE_ARGS+=	--with-libvirt=${LOCALBASE}
LIB_DEPENDS+=		libvirt.so:devel/libvirt
.endif

.include <bsd.port.mk>
