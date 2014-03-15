# $FreeBSD$

PORTNAME=	pkg
DISTVERSION=	1.2.7
CATEGORIES=	ports-mgmt
MASTER_SITES=	\
		http://files.etoilebsd.net/${PORTNAME}/ \
		http://mirror.shatow.net/freebsd/${PORTNAME}/ \
		LOCAL/portmgr
PKGNAMESUFFIX=	-devel

MAINTAINER=	portmgr@FreeBSD.org
COMMENT=	Package manager

LICENSE=	BSD2CLAUSE

USES=		tar:xz uidfix

# Disable CCACHE support because of the chicken/egg problem pkg should always
# With no dependency at all
NO_CCACHE=	yes
USE_LDCONFIG=	yes
MAKE_ARGS+=	PKG_PORTSDIR=${PORTSDIR}

MAKE_ENV+=	WITHOUT_PROFILE=yes __MAKE_CONF=/dev/null SRCCONF=/dev/null \
		PORTREVISION=${PORTREVISION}

# Use a submake as 'deinstall install' needs to reevaluate PKG_CMD
# so that pkg-static is used from the wrkdir
USE_SUBMAKE=	yes

.if !exists(/usr/include/jail.h)
EXTRA_PATCHES=	${FILESDIR}/extra-patch-pkg_pkg.8
.endif

.include <bsd.port.pre.mk>

.if defined(WITH_DEBUG) && !defined(WITHOUT_DEBUG)
MAKE_ARGS+=	DEBUG_FLAGS="${DEBUG_FLAGS}"
.endif

.if defined(WITH_PKGNG)
.if ${WITH_PKGNG} != devel
NO_LATEST_LINK=	yes
.	if !defined(PACKAGE_BUILDING)
IGNORE=	WITH_PKGNG is not defined to 'devel', this version is the devel one
.	endif
.else
LATEST_LINK=   pkg
PKGNAMESUFFIX=
.endif
.if exists(${LOCALBASE}/sbin/pkg_info) || exists(/usr/sbin/pkg_info)
NB_OLDPKGS!=	pkg_info 2>/dev/null | wc -l
.if exists(${PKG_BIN})
NB_NEWPKGS!=	${PKG_INFO} -aq | wc -l
.else
NB_NEWPKGS=	0
.endif
# Only show the pre-everything notice if they have not already
# converted any packages
.if ${NB_OLDPKGS} > 0 && ${NB_NEWPKGS} == 0

pre-everything::
	@${ECHO_CMD} "You are about to convert your system to pkgng while you have ports/packages"; \
	 ${ECHO_CMD} "installed with the old pkg_install tools."; \
	 ${ECHO_CMD} ""; \
	 ${ECHO_CMD} "You can choose to: "; \
	 ${ECHO_CMD} "- keep pkg_install as the package management system by adding this line to /etc/make.conf:"; \
	 ${ECHO_CMD} ""; \
	 ${ECHO_CMD} "    WITHOUT_PKGNG=yes" ; \
	 ${ECHO_CMD} ""; \
	 ${ECHO_CMD} "- switch to pkgng:"; \
	 ${ECHO_CMD} "    1) Add WITHOUT_PKGNG to /etc/make.conf"; \
	 ${ECHO_CMD} "    2) Install ports-mgmt/pkg"; \
	 ${ECHO_CMD} "    3) Convert your package database by running pkg2ng"; \
	 ${ECHO_CMD} "    4) Remove WITHOUT_PKGNG from /etc/make.conf"; \
	 ${ECHO_CMD} ""; \
	exit 1

.endif
.endif
.else
LATEST_LINK=	pkg-devel
.endif

#define PKG_DEPENDS to nothing to avoid infinite loop looking for pkg :)
.if defined(WITH_PKGNG)
PKG_DEPENDS=
.undef INSTALLS_DEPENDS
.if !exists(${LOCALBASE}/sbin/pkg)
PKG_BIN=	${WRKSRC}/pkg/pkg-static
.endif
.endif

PERIODIC_DAILY=		400.status-pkg 411.pkg-backup 490.status-pkg-changes
PERIODIC_SECURITY=	410.pkg-audit 460.pkg-checksum
PERIODIC_ALL=		${PERIODIC_DAILY} ${PERIODIC_SECURITY}

post-install:
	@${INSTALL_DATA} ${WRKSRC}/pkg/pkg.conf.sample ${STAGEDIR}${PREFIX}/etc

.include <bsd.port.post.mk>
