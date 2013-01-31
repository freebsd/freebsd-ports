# Created by:	Bruce M Simpson <bms@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xorp-devel
PORTVERSION=	2009120801
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	bms
DISTNAME=	xorp-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Open source network routing platform, development branch

# Uses libcurses, libcrypto, librt from base system.
LIB_DEPENDS=	boost_regex:${PORTSDIR}/devel/boost-libs \
		pcap:${PORTSDIR}/net/libpcap

CONFLICTS=	xorp-1*

NOMAN=		defined

USE_BZIP2=	yes
USE_GCC=	4.2+
USE_SCONS=	yes
#USE_OPENSSL=	yes
MAKE_JOBS_SAFE=	defined

OPTIONS_DEFINE=	OPTIMIZE ORIGIN SHARED STRIP TCP_RPC
OPTIONS_DEFAULT=	OPTIMIZE ORIGIN SHARED STRIP
OPTIMIZE_DESC=	Build with optimization
ORIGIN_DESC=	Use ORIGIN with shared libraries
SHARED_DESC=	Build with shared libraries
TCP_RPC_DESC=	Use TCP as RPC transport (defaults to AF_LOCAL)

#
# To roll snapshot: as bms: make BOOTSTRAP=defined fetch
#
.if defined(BOOTSTRAP)
FETCH_DEPENDS+=	svn:${PORTSDIR}/devel/subversion
SVN_REV=	11685		# svn tip at epoch 2009120801
SVNROOT_URI=	http://xorp.svn.sourceforge.net/svnroot/xorp

do-fetch:
	${MKDIR} ${WRKDIR}
	svn export -r ${SVN_REV} ${SVNROOT_URI}/trunk/xorp ${WRKSRC}
	cd ${WRKDIR}; tar cvfy ${DISTDIR}/${DISTNAME}.tar.bz2 ${DISTNAME}
.if ${USER} == bms
	${CHMOD} ugo+r ${DISTDIR}/${DISTNAME}.tar.bz2
	scp -p ${DISTDIR}/${DISTNAME}.tar.bz2 \
	    freefall.freebsd.org:public_distfiles/
.endif
.endif # defined(BOOTSTRAP)

.include <bsd.port.options.mk>

XORP_GROUP=	xorp
USE_RC_SUBR=	xorp

SCONS_ARGS+=	prefix=${PREFIX}

.if ${PORT_OPTIONS:MOPTIMIZE}
SCONS_ARGS+=	optimize=yes
.else
SCONS_ARGS+=	optimize=no
.endif

.if ${PORT_OPTIONS:MSHARED}
SCONS_ARGS+=	shared=true
PLIST_SUB+=	XORP_SHLIB=""
USE_LDCONFIG=	${PREFIX}/lib/xorp/lib
. if ${PORT_OPTIONS:MORIGIN}
SCONS_ARGS+=	origin=true
. else
SCONS_ARGS+=	origin=false
. endif
.else
SCONS_ARGS+=	shared=false
PLIST_SUB+=	XORP_SHLIB="@comment "
.endif

.if ${PORT_OPTIONS:MSTRIP}
SCONS_ARGS+=	strip=true
.else
SCONS_ARGS+=	strip=false
.endif

.if ${PORT_OPTIONS:MTCP_RPC}
SCONS_ARGS+=	transport=tcp
.else
SCONS_ARGS+=	transport=local
.endif

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile on sparc64
.endif

post-install:
	${SETENV} ${SCRIPTS_ENV} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
