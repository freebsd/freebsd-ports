# $FreeBSD$

PORTNAME=	pkg
DISTVERSION=	1.14.99.1
_PKG_VERSION=	${DISTVERSION}
CATEGORIES=	ports-mgmt
PKGNAMESUFFIX=	-devel

MAINTAINER=	pkg@FreeBSD.org
COMMENT=	Package manager

LICENSE=	BSD2CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	freebsd
GH_TAGNAME=	3ea3c500

CFLAGS+=	-O0 -g -Wno-error
USE_LDCONFIG=	${PREFIX}/lib/compat/pkg
HAS_CONFIGURE=	yes
PORTDOCS=	NEWS
PORTSCOUT=	ignore:1
CONFIGURE_ARGS=	--mandir=${PREFIX}/man --prefix="${PREFIX}"
CONFIGURE_ENV=	CC_FOR_BUILD="${CC}"

# Use a submake as 'deinstall install' needs to reevaluate PKG_REGISTER
# so that pkg-static is used from the wrkdir
USE_SUBMAKE=	yes

OPTIONS_DEFINE=	DOCS

.if !exists(/usr/include/jail.h)
EXTRA_PATCHES=	${FILESDIR}/extra-patch-docs_pkg.8
.endif

.include <bsd.port.pre.mk>

.if defined(WITH_PKG)
.if ${WITH_PKG} != devel
.	if !defined(PACKAGE_BUILDING)
IGNORE=	WITH_PKG is not defined to 'devel', this version is the devel one
.	endif
.else
PKGNAMESUFFIX=
#define PKG_DEPENDS to nothing to avoid infinite loop looking for pkg :)
PKG_DEPENDS=
.endif
.endif

.undef INSTALLS_DEPENDS
.if !exists(${LOCALBASE}/sbin/pkg) && !defined(CROSS_TOOLCHAIN)
PKG_BIN=	${WRKSRC}/src/pkg-static
.endif

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/compat/pkg
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/NEWS ${STAGEDIR}${DOCSDIR}/NEWS

.include <bsd.port.post.mk>
