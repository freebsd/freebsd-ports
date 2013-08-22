# Created by: MANTANI Nobutaka <nobutaka@nobutaka.com>
# $FreeBSD$

PORTNAME=	w3m
PORTVERSION=	0.5.3
PORTREVISION=	2
CATEGORIES+=	www ipv6
MASTER_SITES=	SF/w3m/w3m/w3m-${PORTVERSION}

MAINTAINER?=	nobutaka@FreeBSD.org
COMMENT?=	A pager/text-based WWW browser

USE_OPENSSL=	yes
LIB_DEPENDS=	gc:${PORTSDIR}/devel/boehm-gc

MAKE_JOBS_UNSAFE=	yes

CONFLICTS?=	ja-w3m-0.5.* ja-w3m-img-0.5.* w3m-img-0.5.*
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gc=${LOCALBASE}

MAN1=		w3m.1 w3mman.1
MANLANG=	"" ja

DOCS=		FAQ.html HISTORY MANUAL.html README \
		README.dict README.func README.m17n STORY.html keymap.default \
		keymap.lynx menu.default menu.submenu

OPTIONS_DEFINE=	JAPANESE INLINE_IMAGE KEY_LYNX DOCS
JAPANESE_DESC=		Japanese messages and migemo support
INLINE_IMAGE_DESC=	Inline image support
KEY_LYNX_DESC=		Keymap like lynx browser

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MJAPANESE}
USES+=		gettext
CONFIGURE_ARGS+=	--enable-japanese=E --with-migemo=yes gt_cv_func_gnugettext1_libintl=yes
DOCS_JP=	${DOCS} README.SSL README.cookie README.keymap README.mailcap \
		README.menu README.migemo

PLIST_SUB+=	JAPANESE=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	JAPANESE="@comment "
.endif

.if ${PORT_OPTIONS:MINLINE_IMAGE}
USE_GNOME=	gtk20
CONFIGURE_ARGS+=	--with-imagelib=gtk2 --enable-image=fb,x11

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

.if ${PORT_OPTIONS:MKEY_LYNX}
CONFIGURE_ARGS+=	--enable-keymap=lynx
.endif

CONFIGURE_ENV=	DEFS="-I${LOCALBASE}/include"

post-patch:
	@${REINPLACE_CMD} -e \
		's|\`\(expr\) \(.*\) : \(.*\)`|`\1 \\( \2 : \3 \\)`|' \
		-e 's|/usr/local|${LOCALBASE}|g' \
		${WRKSRC}/configure
	@${FIND} ${WRKSRC}/doc* -type f \! -name HISTORY \
		-exec ${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|g' {} +

post-install:
.if ${PORT_OPTIONS:MDOCS}
.if ${PORT_OPTIONS:MJAPANESE}
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
.endif
	@${INSTALL_MAN} ${WRKSRC}/scripts/w3mman/w3mman.1 ${PREFIX}/man/ja/man1
.if ${PORT_OPTIONS:MINLINE_IMAGE}
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
