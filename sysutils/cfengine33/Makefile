# Created by: jrhett@netconsonance.com
# $FreeBSD$

PORTNAME=	cfengine
PORTVERSION=	3.3.8
PORTREVISION=	8
CATEGORIES=	sysutils
MASTER_SITES=	https://s3.amazonaws.com/cfengine.package-repos/tarballs/
PKGNAMESUFFIX=	33

MAINTAINER=	cy@FreeBSD.org
#		gjb@FreeBSD.org is also committer for this port
COMMENT=	Systems administration tool for networks

FETCH_BEFORE_ARGS=	-o ${DISTDIR}/${DISTFILES}

CONFLICTS=	cfengine-2* cfengine-3.[245]* cfengine-devel-*

USE_RC_SUBR=	cf-execd cf-serverd

USES=		gmake libtool
USE_LDCONFIG=	yes
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
# EXAMPLESDIR=	${PREFIX}/share/examples/cfengine3
DOCSDIR=	${PREFIX}/share/doc/cfengine
CONFIGURE_ARGS=	--docdir=${DOCSDIR} \
		--htmldir=${DOCSDIR}/html \
		--with-pcre=${LOCALBASE} \
		--enable-fhs
CFLAGS+=	-Wno-error=implicit-function-declaration

LIB_DEPENDS+=	libpcre.so:${PORTSDIR}/devel/pcre

OPTIONS_DEFINE=	PGSQL MYSQL LIBVIRT
OPTIONS_SINGLE=	DB
OPTIONS_SINGLE_DB=	TOKYOCABINET QDBM
TOKYOCABINET_DESC=	Enable TokyoCabinet database backend
QDBM_DESC=	Enable QDBM database backend
PGSQL_DESC=	Enable PostgreSQL integration
MYSQL_DESC=	Enable MySQL integration
LIBVIRT_DESC=	Enable libvirt integration
OPTIONS_DEFAULT=TOKYOCABINET

post-patch:
	@${REINPLACE_CMD} -e '/^htmldir/s!=.*!= @htmldir@!' \
		${WRKSRC}/docs/Makefile.in

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MTOKYOCABINET}
CONFIGURE_ARGS+=	--with-tokyocabinet=${LOCALBASE}
LIB_DEPENDS+=	libtokyocabinet.so:${PORTSDIR}/databases/tokyocabinet
.endif

.if ${PORT_OPTIONS:MQDBM}
CONFIGURE_ARGS+=	--with-qdbm=${LOCALBASE}
LIB_DEPENDS+=	libqdbm.so:${PORTSDIR}/databases/qdbm
.endif

.if ${PORT_OPTIONS:MPGSQL}
USE_PGSQL=		yes
CONFIGURE_ARGS+=	--with-postgresql=${LOCALBASE}
LIB_DEPENDS+=		libpq.so:${PORTSDIR}/databases/postgresql${PGSQL_VER}-client
.endif

.if ${PORT_OPTIONS:MMYSQL}
USE_MYSQL=		yes
CONFIGURE_ARGS+=	--with-mysql=${LOCALBASE}
LIB_DEPENDS+=		libmysqlclient.so:${PORTSDIR}/${_MYSQL_CLIENT}
LDFLAGS+=		-L${LOCALBASE}/lib/mysql
.endif

.if ${PORT_OPTIONS:MLIBVIRT}
CONFIGURE_ARGS+=	--with-libvirt=${LOCALBASE}
LIB_DEPENDS+=		libvirt.so:${PORTSDIR}/devel/libvirt
.endif

.include <bsd.port.mk>
