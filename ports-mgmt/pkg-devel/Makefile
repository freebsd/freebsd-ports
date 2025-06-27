PORTNAME=	pkg
DISTVERSION=	2.2.99.1
_PKG_VERSION=	${DISTVERSION}
CATEGORIES=	ports-mgmt
PKGNAMESUFFIX=	-devel

MAINTAINER=	pkg@FreeBSD.org
COMMENT=	Package manager
WWW=		https://github.com/freebsd/pkg

LICENSE=	BSD2CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	freebsd
GH_TAGNAME=	3f6b36f19

USE_LDCONFIG=	${PREFIX}/lib/compat/pkg
HAS_CONFIGURE=	yes
PORTDOCS=	NEWS
PORTSCOUT=	ignore:1
CONFIGURE_ARGS=	--prefix="${PREFIX}"
CONFIGURE_ENV=	CC_FOR_BUILD="${CC}"

# Use a submake as 'deinstall install' needs to reevaluate PKG_REGISTER
# so that pkg-static is used from the wrkdir
USE_SUBMAKE=	yes

OPTIONS_DEFINE=	DOCS SAN
SAN_DESC=	Enable sanitizers (ASAN and UBSAN)

.if !exists(/usr/include/jail.h)
EXTRA_PATCHES=	${FILESDIR}/extra-patch-docs_pkg.8
.endif

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MSAN}
CONFIGURE_ARGS+=	--with-asan --with-ubsan
.endif

# TODO: activate in april 2021
#.if ${OPSYS} == FreeBSD && ${OSVERSION} > 1400000
#CONFIGURE_ARGS+=	--default-format=tzst
#.endif

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

.if ${PORT_OPTIONS:MSAN}
post-build:
	@(cd ${WRKSRC}/src && \
		${LN} -fs pkg pkg-static)
.endif

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/compat/pkg
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/NEWS ${STAGEDIR}${DOCSDIR}/NEWS
.if ${PORT_OPTIONS:MSAN}
	@${CP} ${STAGEDIR}${PREFIX}/sbin/pkg ${STAGEDIR}${PREFIX}/sbin/pkg-static
.endif

.include <bsd.port.post.mk>
