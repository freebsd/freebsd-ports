PORTNAME=	flow-tools
PORTVERSION=	0.68.6
DISTVERSIONPREFIX=	v
PORTREVISION=	4
CATEGORIES=	net-mgmt

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Suite of tools and library to work with netflow data

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf libtool:keepla python:patch shebangfix
USE_GITHUB=	yes
USE_LDCONFIG=	yes
USE_RC_SUBR=	flow_capture flow_fanout

GH_ACCOUNT=	5u623l20
GH_TAGNAME=	2ca53f5

SHEBANG_FILES=	bin/flow-*
GNU_CONFIGURE=	yes

SUB_LIST=	FLOW_CAPTURE_PIDDIR="${FLOW_CAPTURE_PIDDIR}" \
		FLOW_CAPTURE_SPOOL="${FLOW_CAPTURE_SPOOL}"

USERS=		flowtools
GROUPS=		flowtools

VARDIR?=		/var
FLOW_CAPTURE_SPOOL=	${VARDIR}/db/flows
FLOW_CAPTURE_PIDDIR=	${VARDIR}/run/flow-capture

OPTIONS_DEFINE=	MYSQL OPENSSL PGSQL

PY2TO3_CMD=	${LOCALBASE}/bin/2to3-${PYTHON_VER}
PY2TO3_ARGS=	--fix=all --no-diffs --nobackups --verbose --write

MYSQL_USES=		mysql
MYSQL_CONFIGURE_ON=	--with-mysql="${LOCALBASE}"
OPENSSL_USES=		ssl
OPENSSL_CONFIGURE_ON=	--with-openssl="${OPENSSLBASE}"
PGSQL_USES=		pgsql
PGSQL_CONFIGURE_ON=	--with-postgresql
PGSQL_CONFIGURE_OFF=	--with-postgresql=no

.include <bsd.port.pre.mk>

post-patch:
.if ${PYTHON_MAJOR_VER} >= 3
	${PY2TO3_CMD} ${PY2TO3_ARGS} ${WRKSRC}/bin/flow-*
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}/${PREFIX}/lib/libft.so.0.0.0

post-stage:
.for f in asn.sym filter.cfg ip-prot.sym ip-type.sym map.cfg mask.cfg stat.cfg \
	tag.cfg tag.sym tcp-port.sym xlate.cfg
	@${MV} ${STAGEDIR}${ETCDIR}/${f} ${STAGEDIR}${ETCDIR}/${f}.sample
.endfor

.include <bsd.port.post.mk>
