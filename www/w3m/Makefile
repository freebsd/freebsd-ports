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

W3M_VERSION=	0.2.4
IMG_VERSION=	1.18
M17N_VERSION=	20020108
M17N_BASE_W3M_VERSION=	0.2.4

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	-nonstop --prefix=${PREFIX} \
			--libdir=${PREFIX}/libexec/w3m \
			--helpdir=${PREFIX}/share/doc/w3m \
			--helpdir-ja=${PREFIX}/share/doc/ja/w3m \
			--gc-includedir=${LOCALBASE}/include \
			--gc-libdir=${LOCALBASE}/lib
HOSTNAME!=	/bin/hostname
SCRIPTS_ENV=	HOSTNAME=${HOSTNAME} WRKSRC=${WRKSRC} PREFIX=${PREFIX} \
		CC=${CC} LOCALBASE=${LOCALBASE} JAPANESE=${JAPANESE} \
		USE_OPENSSL="${USE_OPENSSL}" SSL_CFLAGS="${SSL_CFLAGS}" \
		SSL_LIBS="${SSL_LIBS}" EXTRA_SSL_LIBS="${EXTRA_SSL_LIBS}" \
		INLINE_IMAGE=${INLINE_IMAGE} M17N=${M17N}

MAN1=		w3m.1
MANLANG=	""
CFLAGS+=	-pipe

CONFIG_H=	${WRKSRC}/config.h
DOCS=		FAQ.html HISTORY MANUAL.html README \
		README.dict README.func STORY.html keymap.default \
		keymap.lynx menu.default menu.submenu
SED_CMD=	-e "s,%%PREFIX%%,${PREFIX},g" \
		-e "s,%%LOCALBASE%%,${LOCALBASE},g"

.if !defined(WITHOUT_SSL) && exists(/usr/lib/libcrypto.so)
USE_OPENSSL=	yes
.endif

.if defined(M17N)
PORTVERSION:=	${M17N_BASE_W3M_VERSION}+${M17N_VERSION}

MASTER_SITES=	http://www2u.biglobe.ne.jp/~hsaka/w3m/patch/
DISTNAME=	${PORTNAME}-${M17N_BASE_W3M_VERSION}-m17n-${M17N_VERSION}
EXTRA_PATCHES=	${PATCHDIR}/extra-patch-configure.m17n
CONFIGURE_ARGS+=	--suffix=""

PLIST_SUB+=	M17N_ONLY="" NO_M17N="@comment "

# Disable inline image support for w3m-m17n.
.undef INLINE_IMAGE
.else
PLIST_SUB+=	M17N_ONLY="@comment " NO_M17N=""
.endif

.if defined(JAPANESE)
MANLANG+=	ja
DOCS_JP=	${DOCS} README.SSL README.cookie \
		README.keymap README.mailcap README.menu

PLIST_SUB+=	JAPANESE_ONLY=""
.else
PLIST_SUB+=	JAPANESE_ONLY="@comment "
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
PORTVERSION:=	${PORTVERSION}+${IMG_VERSION}
PATCH_SITES=	http://www2u.biglobe.ne.jp/~hsaka/w3m/patch/
PATCHFILES=	${PORTNAME}-${W3M_VERSION}-img-${IMG_VERSION}.patch.gz
PATCH_DIST_STRIP=	-p1

USE_IMLIB=	yes

DOCS+=		README.img
DOCS_JP+=	README.img
PLIST_SUB+=	INLINE_IMAGE_ONLY=""

PKGMESSAGE=	${MASTERDIR}/pkg-message
.else
PLIST_SUB+=	INLINE_IMAGE_ONLY="@comment "

# Don't use pkg-message
PKGMESSAGE=	${NONEXISTENT}
.endif

pre-extract:
.if !defined(WITHOUT_SSL)
	@${ECHO_MSG} "You can disable support for SSL by defining WITHOUT_SSL."
.endif

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
	@${INSTALL_MAN} ${WRKSRC}/doc/w3m.1 ${PREFIX}/man/man1
.if defined(JAPANESE)
	@${INSTALL_MAN} ${WRKSRC}/doc-jp/w3m.1 ${PREFIX}/man/ja/man1
.endif
.if defined(INLINE_IMAGE)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
