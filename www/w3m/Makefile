# New ports collection makefile for:   w3m
# Date Created:			7 Oct 1999
# Whom:				MANTANI Nobutaka <nobutaka@nobutaka.com>
#
# $FreeBSD$
#

PORTNAME=	w3m
PORTVERSION=	${W3M_VERSION}
CATEGORIES+=	www ipv6
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${W3M_VERSION}

MAINTAINER?=	nobutaka@FreeBSD.org

LIB_DEPENDS=	gc.1:${PORTSDIR}/devel/boehm-gc

FORBIDDEN=	"Security vulnerability - access to local files"

W3M_VERSION=			0.3.2
M17N_VERSION=			20021116
M17N_BASE_W3M_VERSION=		${W3M_VERSION}

HAS_CONFIGURE=	yes
USE_REINPLACE=	yes
CONFIGURE_ARGS=	-nonstop --prefix=${PREFIX} \
			--libdir=${PREFIX}/libexec/w3m \
			--helpdir=${PREFIX}/share/doc/w3m \
			--gc-includedir=${LOCALBASE}/include \
			--gc-libdir=${LOCALBASE}/lib \
			-cflags="${CFLAGS}"
HOSTNAME!=	/bin/hostname
SCRIPTS_ENV=	HOSTNAME=${HOSTNAME} WRKSRC=${WRKSRC} PREFIX=${PREFIX} \
		CC=${CC} LOCALBASE=${LOCALBASE} JAPANESE=${JAPANESE} \
		USE_OPENSSL="${USE_OPENSSL}" SSL_CFLAGS="${SSL_CFLAGS}" \
		SSL_LIBS="${SSL_LIBS}" EXTRA_SSL_LIBS="${EXTRA_SSL_LIBS}" \
		INLINE_IMAGE=${INLINE_IMAGE} M17N=${M17N}

MAN1=		w3m.1 w3mman.1
MANLANG=	"" ja

DOCS=		FAQ.html HISTORY MANUAL.html README \
		README.dict README.func STORY.html keymap.default \
		keymap.lynx menu.default menu.submenu

.if !defined(WITHOUT_SSL) && exists(/usr/lib/libcrypto.so)
USE_OPENSSL=	yes
.endif

.if defined(M17N)
PORTVERSION:=	${M17N_BASE_W3M_VERSION}+${M17N_VERSION}
PKGNAMESUFFIX=	-m17n

MASTER_SITES=	http://www2u.biglobe.ne.jp/~hsaka/w3m/patch/
DISTNAME=	${PORTNAME}-${M17N_BASE_W3M_VERSION}-m17n-${M17N_VERSION}
CONFIGURE_ARGS+=	--suffix=""

PLIST_SUB+=	M17N="" NO_M17N="@comment "
.else
PLIST_SUB+=	M17N="@comment " NO_M17N=""
.endif

.if defined(JAPANESE)
RUN_DEPENDS=	migemo:${PORTSDIR}/japanese/migemo

DOCS_JP=	${DOCS} README.SSL README.cookie README.keymap README.mailcap \
		README.menu README.migemo

PLIST_SUB+=	JAPANESE=""
.else
PLIST_SUB+=	JAPANESE="@comment "
.endif

.if defined(USE_OPENSSL)
SSL_CFLAGS=	-I${OPENSSLINC}/openssl -I${OPENSSLINC} ${OPENSSL_CFLAGS}
SSL_LIBS=	-L${OPENSSLLIB} -lssl -lcrypto

MAKE_FLAGS+=	DEFS="${SSL_CFLAGS} -I${LOCALBASE}/include" \
		LIBS="${SSL_LIBS} ${EXTRA_SSL_LIBS} -L${LOCALBASE}/lib"
.else
MAKE_FLAGS+=	DEFS="-I${LOCALBASE}/include" LIBS="-L${LOCALBASE}/lib"
.endif

.if defined(INLINE_IMAGE)
USE_GNOMENG=	yes
USE_GNOME=	gdkpixbuf

DOCS+=		README.img
DOCS_JP+=	README.img
PLIST_SUB+=	INLINE_IMAGE=""

PKGMESSAGE=	${MASTERDIR}/pkg-message
.else
PLIST_SUB+=	INLINE_IMAGE="@comment "

# Don't use pkg-message
PKGMESSAGE=	${NONEXISTENT}
.endif

.if defined(M17N)
.undef EXTRA_PATCHES
.endif

pre-everything::
.if defined(M17N)
	@${ECHO_MSG} "====>"
	@${ECHO_MSG} "====> To enable Japanese message and migemo support, define JAPANESE"
	@${ECHO_MSG} "====> To enable inline image support, define INLINE_IMAGE"
	@${ECHO_MSG} "====>"
.endif

pre-extract:
.if !defined(WITHOUT_SSL)
	@${ECHO_MSG} "You can disable support for SSL by defining WITHOUT_SSL."
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|\`\(expr\) \(.*\) : \(.*\)`|`\1 \\( \2 : \3 \\)`|' \
		${WRKSRC}/configure

post-install:
.if !defined(NOPORTDOCS)
.if defined(JAPANESE)
	@${MKDIR} ${PREFIX}/share/doc/ja/w3m
	@cd ${WRKSRC}/doc-jp; \
	for i in ${DOCS_JP} ; do \
		${INSTALL_DATA} $$i ${PREFIX}/share/doc/ja/w3m/ ; \
	done
.endif
	@cd ${WRKSRC}/doc; \
	${MKDIR} ${PREFIX}/share/doc/w3m/; \
	for i in ${DOCS} ; do \
		${INSTALL_DATA} $$i ${PREFIX}/share/doc/w3m/ ; \
	done
.if defined(M17N)
	@${INSTALL_DATA} ${WRKSRC}/doc/README.m17n ${PREFIX}/share/doc/w3m
.endif
.endif
	@${INSTALL_MAN} ${WRKSRC}/scripts/w3mman/w3mman.1 ${PREFIX}/man/ja/man1
.if defined(INLINE_IMAGE)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
