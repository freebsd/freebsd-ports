# Created by: MANTANI Nobutaka <nobutaka@nobutaka.com>
# $FreeBSD$

PORTNAME=	w3m
PORTVERSION=	0.5.3
PORTREVISION=	1
CATEGORIES+=	www ipv6
MASTER_SITES=	SF/w3m/w3m/w3m-${PORTVERSION}

MAINTAINER?=	nobutaka@FreeBSD.org
COMMENT?=	A pager/text-based WWW browser

USE_OPENSSL=	yes
LIB_DEPENDS=	gc.1:${PORTSDIR}/devel/boehm-gc

MAKE_JOBS_UNSAFE=	yes

CONFLICTS?=	ja-w3m-0.5.* ja-w3m-img-0.5.* w3m-m17n-0.5.* w3m-img-0.5.* w3m-m17n-img-0.5.*
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gc=${LOCALBASE}

MAN1=		w3m.1 w3mman.1
MANLANG=	"" ja

DOCS=		FAQ.html HISTORY MANUAL.html README \
		README.dict README.func STORY.html keymap.default \
		keymap.lynx menu.default menu.submenu

.if !defined(MASTERDIR)
OPTIONS=	M17N "Multilingualization support" off \
		JAPANESE "Japanese messages and migemo support" off \
		INLINE_IMAGE "Inline image support" off \
		KEY_LYNX "Keymap like lynx browser" off

.include <bsd.port.options.mk>
.endif

.if defined(WITH_M17N)
CONFIGURE_ARGS+=	--enable-m17n
PLIST_SUB+=	M17N=""
.else
.if !defined(WITH_JAPANESE)
CONFIGURE_ARGS+=	--disable-m17n
PLIST_SUB+=	M17N="@comment "
.endif
.endif

.if defined(WITH_JAPANESE)
USE_GETTEXT=		yes
CONFIGURE_ARGS+=	--enable-m17n --enable-japanese=E --with-migemo=yes gt_cv_func_gnugettext1_libintl=yes
DOCS_JP=	${DOCS} README.SSL README.cookie README.keymap README.mailcap \
		README.menu README.migemo

PLIST_SUB+=	JAPANESE="" M17N=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	JAPANESE="@comment "
.endif

.if defined(WITH_INLINE_IMAGE)
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

.if defined(WITH_KEY_LYNX)
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
.if !defined(NOPORTDOCS)
.if defined(WITH_JAPANESE)
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
.if defined(WITH_M17N) || defined(WITH_JAPANESE)
	@${INSTALL_DATA} ${WRKSRC}/doc/README.m17n ${PREFIX}/share/doc/w3m
.endif
.endif
	@${INSTALL_MAN} ${WRKSRC}/scripts/w3mman/w3mman.1 ${PREFIX}/man/ja/man1
.if defined(WITH_INLINE_IMAGE)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
