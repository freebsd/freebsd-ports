PORTNAME=	pkg
DISTVERSION=	2.2.2
_PKG_VERSION=	${DISTVERSION}
CATEGORIES=	ports-mgmt

MAINTAINER=	pkg@FreeBSD.org
COMMENT=	Package manager
WWW=		https://github.com/freebsd/pkg

LICENSE=	BSD2CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	freebsd

USE_LDCONFIG=	${PREFIX}/lib/compat/pkg
HAS_CONFIGURE=	yes
PORTDOCS=	NEWS
PORTSCOUT=	ignore:1
CONFIGURE_ARGS=	--prefix="${PREFIX}"
CONFIGURE_ENV=	CC_FOR_BUILD="${CC}"

# Use a submake as 'deinstall install' needs to reevaluate PKG_REGISTER
# so that pkg-static is used from the wrkdir
USE_SUBMAKE=	yes
CFLAGS+=	-Wno-error

OPTIONS_DEFINE=	DOCS

.if !exists(/usr/include/jail.h)
EXTRA_PATCHES=	${FILESDIR}/extra-patch-docs_pkg.8
.endif

.include <bsd.port.pre.mk>

.if defined(WITH_DEBUG)
MAKE_ARGS+=	DEBUG_FLAGS="${DEBUG_FLAGS}"
.endif

.if defined(WITH_PKG)
.if ${WITH_PKG} == devel
IGNORE=	WITH_PKG is defined to 'devel', this version is the stable one
.endif
.endif

#define PKG_DEPENDS to nothing to avoid infinite loop looking for pkg :)
PKG_DEPENDS=
.undef INSTALLS_DEPENDS

# Use the internal pkg instead, generally, unless this is a cross-build,
# in which case that won't work. Hope for the best then.
.if !defined(CROSS_TOOLCHAIN)
PKG_BIN=	${WRKSRC}/src/pkg-static
.endif

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/compat/pkg

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/NEWS ${STAGEDIR}${DOCSDIR}/NEWS

.include <bsd.port.post.mk>
