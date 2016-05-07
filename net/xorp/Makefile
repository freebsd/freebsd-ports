# Created by: Bruce M Simpson <bms@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xorp
PORTVERSION=	1.8.5
DISTVERSIONPREFIX=	${PORTNAME}-
CATEGORIES=	net

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	EXtensible Open Router Platform

LICENSE=	GPLv2

LIB_DEPENDS=	libboost_regex.so:devel/boost-libs \
		libpcap.so:net/libpcap

CONFLICTS_INSTALL=	xorp-devel-*

USES=		tar:bzip2 ncurses scons shebangfix compiler:env python:2,build
USE_GITHUB=	yes
USE_OPENSSL=	yes
USE_RC_SUBR=	xorp
GH_ACCOUNT=	greearb
GH_PROJECT=	${PORTNAME}.ct
SHEBANG_FILES=	xrl/scripts/clnt-gen xrl/scripts/tgt-gen
python_OLD_CMD=	.*python
WRKSRC=		${WRKDIR}/${GH_PROJECT}-${DISTVERSIONPREFIX}${DISTVERSION}/${PORTNAME}
MAKE_ARGS=	prefix=${PREFIX} enable_boost=1
SUB_FILES=	pkg-message
GROUPS=		xorp
BROKEN_sparc64=		Does not compile on sparc64

OPTIONS_DEFINE=	OPTIMIZE ORIGIN SHARED STRIP TCP_RPC
OPTIONS_DEFAULT=	OPTIMIZE ORIGIN SHARED STRIP
OPTIONS_SUB=	yes
OPTIMIZE_DESC=	Build with optimization
OPTIMIZE_MAKE_ARGS=	optimize=highest
OPTIMIZE_MAKE_ARGS_OFF=	optimize=no
ORIGIN_DESC=	Use ORIGIN with shared libraries
ORIGIN_MAKE_ARGS=	origin=true
ORIGIN_MAKE_ARGS_OFF=	origin=false
SHARED_DESC=	Build with shared libraries
SHARED_MAKE_ARGS=	shared=true
SHARED_MAKE_ARGS_OFF=	shared=false
SHARED_USE_ON=	LDCONFIG=${PREFIX}/lib/xorp/lib
STRIP_MAKE_ARGS=	strip=true
STRIP_MAKE_ARGS_OFF=	strip=false
TCP_RPC_DESC=	Use TCP as RPC transport (defaults to AF_LOCAL)
TCP_RPC_MAKE_ARGS=	transport=tcp
TCP_RPC_MAKE_ARGS_OFF=	transport=local

.include <bsd.port.pre.mk>

post-patch:
	${REINPLACE_CMD} 's,%%LOCALBASE%%,${LOCALBASE},' ${WRKSRC}/SConstruct

post-install:
	${INSTALL_DATA} ${WRKSRC}/rtrmgr/config/multicast4.boot \
	    ${STAGEDIR}${PREFIX}/etc/xorp.conf.sample

.include <bsd.port.post.mk>
