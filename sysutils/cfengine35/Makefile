# Created by: jrhett@netconsonance.com
# $FreeBSD$

PORTNAME=	cfengine
PORTVERSION=	3.5.0
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://cfengine.com/source-code/download?file=

MAINTAINER=	cy@FreeBSD.org
#		gjb@FreeBSD.org is also committer for this port
COMMENT=	A systems administration tool for networks

.if !defined(MASTERDIR)
PKGNAMESUFFIX=	35
LATEST_LINK=	cfengine35
.endif

FETCH_BEFORE_ARGS=	-o ${DISTDIR}/${DISTFILES}

CONFLICTS=	cfengine-[23]*

USE_RC_SUBR=	cf-execd cf-serverd

USE_LDCONFIG=	yes
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
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

LIB_DEPENDS+=	pcre:${PORTSDIR}/devel/pcre

OPTIONS_DEFINE=	PGSQL MYSQL LIBVIRT
OPTIONS_SINGLE=	DB
OPTIONS_SINGLE_DB=	TOKYOCABINET QDBM
TOKYOCABINET_DESC=	Enable TokyoCabinet database backend
QDBM_DESC=	Enable QDBM database backend
PGSQL_DESC=	Enable PostgreSQL integration
MYSQL_DESC=	Enable MySQL integration
LIBVIRT_DESC=	Enable libvirt integration
OPTIONS_DEFAULT=TOKYOCABINET

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MTOKYOCABINET}
CONFIGURE_ARGS+=	--with-tokyocabinet=${LOCALBASE}
LIB_DEPENDS+=	tokyocabinet.9:${PORTSDIR}/databases/tokyocabinet
.endif

.if ${PORT_OPTIONS:MQDBM}
CONFIGURE_ARGS+=	--with-qdbm=${LOCALBASE}
LIB_DEPENDS+=	qdbm.14:${PORTSDIR}/databases/qdbm
.endif

.if ${PORT_OPTIONS:MPGSQL}
USE_PGSQL=		yes
CONFIGURE_ARGS+=	--with-postgresql=${LOCALBASE}
LIB_DEPENDS+=		pq:${PORTSDIR}/databases/postgresql${PGSQL_VER}-client
.endif

.if ${PORT_OPTIONS:MMYSQL}
USE_MYSQL=		yes
CONFIGURE_ARGS+=	--with-mysql=${LOCALBASE}
LIB_DEPENDS+=		mysqlclient:${PORTSDIR}/${_MYSQL_CLIENT}
LDFLAGS+=		-L${LOCALBASE}/lib/mysql
.endif

.if ${PORT_OPTIONS:MLIBVIRT}
CONFIGURE_ARGS+=	--with-libvirt=${LOCALBASE}
LIB_DEPENDS+=		virt.1001:${PORTSDIR}/devel/libvirt
.endif

.include <bsd.port.post.mk>
