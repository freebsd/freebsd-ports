PORTNAME=	orch
PORTVERSION=	0.1
CATEGORIES=	sysutils
MASTER_SITES=	https://git.kevans.dev/kevans/${PORTNAME}/archive/${PORTVERSION}.tar.gz?dummy=/

MAINTAINER=	kevans@FreeBSD.org
COMMENT=	Program orchestration tool scripted with lua
WWW=		https://git.kevans.dev/kevans/orch

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		lua:52-54 uidfix

WRKSRC=		${WRKDIR}/${PORTNAME}

ORCHLUA_PATH=	${PREFIX}/share/${PORTNAME}

MAKE_ENV+=	BINDIR="${PREFIX}/bin" \
		EXAMPLESDIR="${ORCHLUA_PATH}/examples" \
		MANDIR="${PREFIX}/share/man/man" \
		LUA_INCDIR="${LUA_INCDIR}" \
		LUA_LIB="-L${LUA_LIBDIR} -llua-${LUA_VER}" \
		ORCHLUA_PATH="${ORCHLUA_PATH}"

.include <bsd.port.pre.mk>

# uidfix won't cover custom directories like this, so we'll hit it ourselves.
.if ${UID} != 0
MAKE_ENV+=	FILESDIR_OWN=${UID} FILESDIR_GRP=${GID}
MAKE_ENV+=	EXAMPLESDIR_OWN=${UID} EXAMPLESDIR_GRP=${GID}
.endif

pre-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/bin ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.post.mk>
