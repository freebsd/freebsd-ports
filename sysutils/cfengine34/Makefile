# Created by: jrhett@netconsonance.com
# $FreeBSD$

PORTNAME=	cfengine
PORTVERSION=	3.4.5
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	http://cfengine.com/source-code/download?file=

MAINTAINER=	cy@FreeBSD.org
#		gjb@FreeBSD.org is also committer for this port
COMMENT=	A systems administration tool for networks

.if !defined(MASTERDIR)
PKGNAMESUFFIX=	34
LATEST_LINK=	cfengine34
.endif

FETCH_BEFORE_ARGS=	-o ${DISTDIR}/${DISTFILES}

CONFLICTS=	cfengine-2* cfengine-3.[235]* cfengine-devel-*

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
OPTIONS_SINGLE=	BACKEND
OPTIONS_SINGLE_BACKEND=	TOKYOCABINET QDBM
OPTIONS_DEFAULT=	TOKYOCABINET

TOKYOCABINET_DESC=	Use TokyoCabinet as backend db
QDBM_DESC=	Use QDBM as backend db
PGSQL_DESC=	Enable PostgreSQL connector
MYSQL_DESC=	Enable MySQL connector
LIBVIRT_DESC=	Enable libvirt compatibility

NO_STAGE=	yes
.include <bsd.port.options.mk>

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
LIB_DEPENDS+=		libvirt.so:${PORTSDIR}/devel/libvirt
.endif

MAN8=	cf-agent.8	cf-key.8	cf-monitord.8	\
	cf-report.8	cf-serverd.8	cf-execd.8	\
	cf-promises.8	cf-runagent.8

post-patch:
		@${REINPLACE_CMD} -e '/^htmldir/s!=.*!= @htmldir@!'\
				  ${WRKSRC}/docs/Makefile.in

.include <bsd.port.mk>
