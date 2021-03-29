PORTNAME=	pam_xdg
PORTVERSION=	s20210329
CATEGORIES=	sysutils

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	PAM module to manage XDG Base Directories

LICENSE=	ISCL

USES=		uidfix
USE_GITHUB=	yes
GH_ACCOUNT=	jbeich # mirror
GH_PROJECT=	s-toolbox
GH_TAGNAME=	2433f8b
PLIST_FILES=	lib/${PORTNAME}.so \
		share/man/man8/${PORTNAME}.8.gz

# pam_xdg.makefile is too crufty, so roll our own
MAKEFILE=	bsd.lib.mk
MAKE_ARGS+=	SHLIB_NAME="${PORTNAME}.so" MAN="${PORTNAME}.8" \
		SRCS="${PORTNAME}.c" LDADD="-lpam" \
		LIBDIR="${PREFIX}/lib" SHAREDIR="${PREFIX}/share"
LDFLAGS+=	-Wl,-z,defs

post-patch:
	@${REINPLACE_CMD} \
		-e '/#define/ { \
			s,/etc,${PREFIX}&,; \
			s,/usr/local,${PREFIX},; \
			s,/run,/var&,; \
		}' \
		${WRKSRC}/${PORTNAME}.c

.include <bsd.port.mk>
