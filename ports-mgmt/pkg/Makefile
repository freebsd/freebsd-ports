# $FreeBSD$

PORTNAME=	pkg
DISTVERSION=	1.8.3
_PKG_VERSION=	${DISTVERSION}
CATEGORIES=	ports-mgmt
MASTER_SITES=	\
		http://files.etoilebsd.net/${PORTNAME}/ \
		LOCAL/portmgr \
		http://mirror.shatow.net/freebsd/${PORTNAME}/ \

MAINTAINER=	pkg@FreeBSD.org
COMMENT=	Package manager

LICENSE=	BSD2CLAUSE

USE_LDCONFIG=	yes
USES=		libtool tar:xz
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-maintainer-mode
INSTALL_TARGET=	install-strip

# Use a submake as 'deinstall install' needs to reevaluate PKG_CMD
# so that pkg-static is used from the wrkdir
USE_SUBMAKE=	yes
CFLAGS+=	-Wno-error

.if !exists(/usr/include/jail.h)
EXTRA_PATCHES=	${FILESDIR}/extra-patch-docs_pkg.8
.endif

.include <bsd.port.pre.mk>

.if defined(WITH_DEBUG) && !defined(WITHOUT_DEBUG)
MAKE_ARGS+=	DEBUG_FLAGS="${DEBUG_FLAGS}"
.endif

.if defined(WITH_PKG)
.if ${WITH_PKG} == devel
IGNORE=	WITH_PKG is defined to 'devel', this version is the stable one
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
.if ${NB_OLDPKGS} > 0 && ${NB_NEWPKGS} == 0 && !defined(UPGRADEPKG)

pre-everything::
	@${ECHO_CMD} "You are about to convert your system to pkg while you have ports/packages"; \
	 ${ECHO_CMD} "installed with the old pkg_install tools."; \
	 ${ECHO_CMD} ""; \
	 ${ECHO_CMD} "To switch to pkg:"; \
	 ${ECHO_CMD} "    1) Install ports-mgmt/pkg"; \
	 ${ECHO_CMD} "       cd ports-mgmt/pkg && make UPGRADEPKG=1 install clean"; \
	 ${ECHO_CMD} "    2) Convert your package database by running pkg2ng"; \
	 ${ECHO_CMD} ""; \
	exit 1

.endif
.endif
.endif

#define PKG_DEPENDS to nothing to avoid infinite loop looking for pkg :)
PKG_DEPENDS=
.undef INSTALLS_DEPENDS
PKG_BIN=	${WRKSRC}/src/pkg-static

post-install:
	@${MV} ${STAGEDIR}${PREFIX}/lib/libpkg_static.a \
		${STAGEDIR}${PREFIX}/lib/libpkg.a

.include <bsd.port.post.mk>
