# New ports collection makefile for:	xorp
# Date created:		22nd September 2006
# Whom:			Bruce M Simpson <bms@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xorp-devel
PORTVERSION=	2009120801
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	bms
DISTNAME=	xorp-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Open source network routing platform, development branch

# Uses libcurses, libcrypto, librt from base system.
BUILD_DEPENDS=	${LOCALBASE}/include/boost/version.hpp:${PORTSDIR}/devel/boost-libs
LIB_DEPENDS=	boost_regex.4:${PORTSDIR}/devel/boost-libs \
		pcap.1:${PORTSDIR}/net/libpcap

CONFLICTS=	xorp-1*

NOMAN=		defined

USE_BZIP2=	yes
USE_GCC=	4.2+
USE_SCONS=	yes
#USE_OPENSSL=	yes
MAKE_JOBS_SAFE=	defined

OPTIONS=								\
	    OPTIMIZE	 "Build with optimization" On			\
	    ORIGIN	 "Use ORIGIN with shared libraries" On		\
	    SHARED	 "Build with shared libraries" On		\
	    STRIP	 "Strip binaries before installing" On		\
	    TCP_RPC	 "Use TCP as RPC transport (defaults to AF_LOCAL)" Off

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

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700000
IGNORE=		unsupported on FreeBSD versions prior to 7.0
.endif

XORP_GROUP=	xorp
USE_RC_SUBR=	xorp

SCONS_ARGS+=	prefix=${PREFIX}

.if defined(WITHOUT_OPTIMIZE)
SCONS_ARGS+=	optimize=no
.else
SCONS_ARGS+=	optimize=yes
.endif

.if defined(WITHOUT_SHARED)
SCONS_ARGS+=	shared=false
PLIST_SUB+=	XORP_SHLIB="@comment "
.else
SCONS_ARGS+=	shared=true
PLIST_SUB+=	XORP_SHLIB=""
USE_LDCONFIG=	${PREFIX}/lib/xorp/lib
. if defined (WITHOUT_ORIGIN)
SCONS_ARGS+=	origin=false
. else
SCONS_ARGS+=	origin=true
. endif
.endif

.if defined(WITHOUT_STRIP)
SCONS_ARGS+=	strip=false
.else
SCONS_ARGS+=	strip=true
.endif

.if defined(WITH_TCP_RPC)
SCONS_ARGS+=	transport=tcp
.else
SCONS_ARGS+=	transport=local
.endif

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile on sparc64
.endif

post-install:
	${SETENV} ${SCRIPTS_ENV} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
