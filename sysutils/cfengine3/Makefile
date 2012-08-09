
# Date created:		February 2, 2009
# Whom:			jrhett@netconsonance.com
#
# $FreeBSD$
#

PORTNAME=	cfengine
PORTVERSION=	3.3.5
CATEGORIES=	sysutils
MASTER_SITES=	http://cfengine.com/source-code/download?file=

MAINTAINER=	cy@FreeBSD.org
COMMENT=	A systems administration tool for networks
LATEST_LINK=	cfengine3
FETCH_BEFORE_ARGS=	-o ${DISTDIR}/${DISTFILES}

CONFLICTS=	cfengine-2*

USE_RC_SUBR=	cf-execd cf-serverd

USE_LDCONFIG=	yes
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
# EXAMPLESDIR=	${PREFIX}/share/examples/cfengine3
DOCSDIR=	${PREFIX}/share/doc/cfengine
CONFIGURE_ARGS=	--docdir=${DOCSDIR} \
		--htmldir=${DOCSDIR}/html \
		--mandir=${PREFIX}/man \
		--with-pcre=${LOCALBASE} \
		--enable-fhs

LIB_DEPENDS+=	pcre.1:${PORTSDIR}/devel/pcre

OPTIONS=	TOKYOCABINET	"Enable TokyoCabinet support"		on \
		QDBM	"Enable QDBM support"				off \
		PGSQL	"Enable PostgreSQL connector"			off \
		MYSQL	"Enable MySQL connector"			off \
		LIBVIRT	"Enable libvirt compatibility"			off

.include <bsd.port.pre.mk>

.if defined(WITH_TOKYOCABINET) && defined(WITH_QDBM)
BROKEN=		TOKYOCABINET and QDBM are mutuallly exclusive
.endif

.if !defined(WITH_TOKYOCABINET) && !defined(WITH_QDBM)
BROKEN=		TOKYOCABINET or QDBM must be defined
.endif

.if defined(WITH_TOKYOCABINET)
CONFIGURE_ARGS+=	--with-tokyocabinet=${LOCALBASE}
LIB_DEPENDS+=	tokyocabinet.9:${PORTSDIR}/databases/tokyocabinet
.endif

.if defined(WITH_QDBM)
CONFIGURE_ARGS+=	--with-qdbm=${LOCALBASE}
LIB_DEPENDS+=	qdbm.14:${PORTSDIR}/databases/qdbm
.endif

.if defined(WITH_PGSQL)
USE_PGSQL=		yes
CONFIGURE_ARGS+=	--with-postgresql=${LOCALBASE}
LIB_DEPENDS+=		pq:${PORTSDIR}/databases/postgresql${PGSQL_VER}-client
.endif

.if defined(WITH_MYSQL)
USE_MYSQL=		yes
CONFIGURE_ARGS+=	--with-mysql=${LOCALBASE}
LIB_DEPENDS+=		mysqlclient:${PORTSDIR}/${_MYSQL_CLIENT}
LDFLAGS+=		-L${LOCALBASE}/lib/mysql
.endif

.if defined(WITH_LIBVIRT)
CONFIGURE_ARGS+=	--with-libvirt=${LOCALBASE}
LIB_DEPENDS+=		virt:${PORTSDIR}/devel/libvirt
.endif

MAN8=	cf-agent.8	cf-key.8	cf-monitord.8	\
	cf-report.8	cf-serverd.8	cf-execd.8	\
	cf-know.8	cf-promises.8	cf-runagent.8

post-patch:
		@${REINPLACE_CMD} -e '/^htmldir/s!=.*!= @htmldir@!'\
				  ${WRKSRC}/docs/Makefile.in

.include <bsd.port.post.mk>
