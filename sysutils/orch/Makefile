PORTNAME=	orch
PORTVERSION=	0.1
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	https://git.kevans.dev/kevans/${PORTNAME}/archive/${PORTVERSION}.tar.gz?dummy=/

MAINTAINER=	kevans@FreeBSD.org
COMMENT=	Program orchestration tool scripted with lua
WWW=		https://git.kevans.dev/kevans/orch

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		lua:52-54 uidfix

PATCH_DIST_STRIP=	-p1
PATCH_SITES=	https://git.kevans.dev/kevans/orch/commit/
# Add script dir to $PATH rather than some custom searching
PATCHFILES+=	b18ce0c42fc62e0e74a05cfd3286f664889b27d3.patch
# Add a `make check` target for easier testing
PATCHFILES+=	4d7797a706e57d1c7c6e0ed63c7bd86d4b0f2d71.patch

WRKSRC=		${WRKDIR}/${PORTNAME}

ORCHLUA_PATH=	${PREFIX}/share/${PORTNAME}

MAKE_ENV+=	BINDIR="${PREFIX}/bin" \
		EXAMPLESDIR="${ORCHLUA_PATH}/examples" \
		MANDIR="${PREFIX}/share/man/man" \
		LUA_INCDIR="${LUA_INCDIR}" \
		LUA_LIB="-L${LUA_LIBDIR} -llua-${LUA_VER}" \
		ORCHLUA_PATH="${ORCHLUA_PATH}"
TEST_TARGET=	check

.include <bsd.port.pre.mk>

# uidfix won't cover custom directories like this, so we'll hit it ourselves.
.if ${UID} != 0
MAKE_ENV+=	FILESDIR_OWN=${UID} FILESDIR_GRP=${GID}
MAKE_ENV+=	EXAMPLESDIR_OWN=${UID} EXAMPLESDIR_GRP=${GID}
.endif

post-patch:
	# XXX This can go away in the next version; patch(1) won't take the hint of
	# the file mode from the patch, so we just fix it here in case one wants to
	# run the tests
	@${CHMOD} +x ${WRKSRC}/tests/my_cat

pre-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/bin ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.post.mk>
