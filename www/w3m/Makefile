# New ports collection makefile for:   w3m
# Date Created:			7 Oct 1999
# Whom:				MANTANI Nobutaka <nobutaka@nobutaka.com>
#
# $FreeBSD$
#

PORTNAME=	w3m
PORTVERSION=	${W3M_VERSION}
CATEGORIES+=	www ipv6
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	nobutaka
#MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
#MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	w3m-${W3M_VERSION}.${SNAPDATE}

MAINTAINER?=	nobutaka@FreeBSD.org
COMMENT?=	A pager/text-based WWW browser

LIB_DEPENDS=	gc.1:${PORTSDIR}/devel/boehm-gc

W3M_VERSION=	0.4.2
SNAPDATE=	20040111

GNU_CONFIGURE=	yes
USE_REINPLACE=	yes

CONFIGURE_ENV=	DEFS="-I${LOCALBASE}/include"
WRKSRC=		${WRKDIR}/w3m

MAN1=		w3m.1 w3mman.1
MANLANG=	"" ja

DOCS=		FAQ.html HISTORY MANUAL.html README \
		README.dict README.func STORY.html keymap.default \
		keymap.lynx menu.default menu.submenu

.if !defined(WITHOUT_SSL) && exists(/usr/lib/libcrypto.so)
USE_OPENSSL=	yes
.else
CONFIGURE_ARGS+=	--without-ssl
.endif

.if defined(M17N)
CONFIGURE_ARGS+=	--enable-m17n
PLIST_SUB+=	M17N=""
.else
.if !defined(JAPANESE)
CONFIGURE_ARGS+=	--disable-m17n
PLIST_SUB+=	M17N="@comment "
.endif
.endif

.if defined(JAPANESE)
CONFIGURE_ARGS+=	--enable-m17n --enable-japanese=E --with-migemo=yes
DOCS_JP=	${DOCS} README.SSL README.cookie README.keymap README.mailcap \
		README.menu README.migemo

PLIST_SUB+=	JAPANESE="" M17N=""
.else
PLIST_SUB+=	JAPANESE="@comment "
.endif

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
LIB_DEPENDS+=		intl.5:${PORTSDIR}/devel/gettext-old
PLIST_SUB+=	NLS=""
.endif

.if defined(INLINE_IMAGE)
USE_GNOME=	gdkpixbuf
CONFIGURE_ARGS+=	--with-imagelib=gdk-pixbuf

DOCS+=		README.img
DOCS_JP+=	README.img
PLIST_SUB+=	INLINE_IMAGE=""

PKGMESSAGE=	${MASTERDIR}/pkg-message
.else
CONFIGURE_ARGS+=	--enable-image=no
PLIST_SUB+=	INLINE_IMAGE="@comment "

# Don't use pkg-message
PKGMESSAGE=	${NONEXISTENT}
.endif

pre-everything::
	@${ECHO_MSG} "===>"
	@${ECHO_MSG} "===> You can enable some features by defining following variables."
	@${ECHO_MSG} "===>"
.if defined(M17N)
	@${ECHO_MSG} "===> M17N         (multilingualization, enabled)"
.else
	@${ECHO_MSG} "===> M17N         (multilingualization)"
.endif
.if defined(JAPANESE)
	@${ECHO_MSG} "===> JAPANESE     (Japanese messages and migemo support, enabled)"
.else
	@${ECHO_MSG} "===> JAPANESE     (Japanese messages and migemo support)"
.endif
.if defined(INLINE_IMAGE)
	@${ECHO_MSG} "===> INLINE_IMAGE (inline image support, enabled)"
.else
	@${ECHO_MSG} "===> INLINE_IMAGE (inline image support)"
.endif
	@${ECHO_MSG} "===>"
	@${ECHO_MSG} "===> You can disable some features by defining following variables."
	@${ECHO_MSG} "===>"
.if defined(WITHOUT_SSL)
	@${ECHO_MSG} "===> WITHOUT_SSL (disabled)"
.else
	@${ECHO_MSG} "===> WITHOUT_SSL"
.endif
.if defined(WITHOUT_NLS)
	@${ECHO_MSG} "===> WITHOUT_NLS (disabled)"
.else
	@${ECHO_MSG} "===> WITHOUT_NLS"
.endif
	@${ECHO_MSG} "===>"

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
.if defined(M17N) || defined(JAPANESE)
	@${INSTALL_DATA} ${WRKSRC}/doc/README.m17n ${PREFIX}/share/doc/w3m
.endif
.endif
	@${INSTALL_MAN} ${WRKSRC}/scripts/w3mman/w3mman.1 ${PREFIX}/man/ja/man1
.if defined(INLINE_IMAGE)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
