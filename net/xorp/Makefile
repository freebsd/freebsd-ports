# Created by: Bruce M Simpson <bms@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xorp
PORTVERSION=	1.8.5
DISTVERSIONSUFFIX=	-src
CATEGORIES=	net
MASTER_SITES=	http://www.xorp.org/releases/${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The eXtensible Open Router Platform

LICENSE=	GPLv2

LIB_DEPENDS=	libboost_regex.so:${PORTSDIR}/devel/boost-libs \
		libpcap.so:${PORTSDIR}/net/libpcap

CONFLICTS_INSTALL=	xorp-devel-*

EXTRACT_AFTER_ARGS=	--no-same-owner --no-same-permissions -s /^xorp/${DISTNAME}/
GROUPS=		xorp
USES=		tar:bzip2 ncurses scons shebangfix compiler:env python:2,build
USE_OPENSSL=	yes
USE_RC_SUBR=	xorp
SHEBANG_FILES=	xrl/scripts/clnt-gen xrl/scripts/tgt-gen
python_OLD_CMD=	.*python
python_CMD=	${PYTHON_CMD}
SUB_FILES=	pkg-message
XORP_SAMPLECONF=	rtrmgr/config/multicast4.boot

BROKEN_sparc64=		Does not compile on sparc64

OPTIONS_DEFINE=	OPTIMIZE ORIGIN SHARED STRIP TCP_RPC
OPTIONS_DEFAULT=	OPTIMIZE ORIGIN SHARED STRIP
OPTIMIZE_DESC=	Build with optimization
ORIGIN_DESC=	Use ORIGIN with shared libraries
SHARED_DESC=	Build with shared libraries
TCP_RPC_DESC=	Use TCP as RPC transport (defaults to AF_LOCAL)

MAKE_ARGS=	prefix=${PREFIX} enable_boost=1

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MOPTIMIZE}
MAKE_ARGS+=	optimize=highest
.else
MAKE_ARGS+=	optimize=no
.endif

.if ${PORT_OPTIONS:MSHARED}
MAKE_ARGS+=	shared=true
PLIST_SUB+=	XORP_SHLIB=""
USE_LDCONFIG=	${PREFIX}/lib/xorp/lib
. if ${PORT_OPTIONS:MORIGIN}
MAKE_ARGS+=	origin=true
. else
MAKE_ARGS+=	origin=false
. endif
.else
MAKE_ARGS+=	shared=false
PLIST_SUB+=	XORP_SHLIB="@comment "
.endif

.if ${PORT_OPTIONS:MSTRIP}
MAKE_ARGS+=	strip=true
.else
MAKE_ARGS+=	strip=false
.endif

.if ${PORT_OPTIONS:MTCP_RPC}
MAKE_ARGS+=	transport=tcp
.else
MAKE_ARGS+=	transport=local
.endif

post-patch:
	${REINPLACE_CMD} 's,%%LOCALBASE%%,${LOCALBASE},' ${WRKSRC}/SConstruct
.if ${COMPILER_TYPE} == "clang"
	${REINPLACE_CMD} 's,-Werror,& -Wno-unused-function,' ${WRKSRC}/SConstruct
.endif

post-install:
	${CP} -p ${WRKSRC}/${XORP_SAMPLECONF} ${STAGEDIR}${PREFIX}/etc/xorp.conf.sample

.include <bsd.port.post.mk>
