# Created by: MANTANI Nobutaka <nobutaka@nobutaka.com>
# $FreeBSD$

PORTNAME=	w3m
PORTVERSION=	0.5.3.${SNAPDATE}
CATEGORIES+=	www

MAINTAINER?=	nobutaka@FreeBSD.org
COMMENT?=	Pager/text-based WWW browser

LICENSE=	w3m
LICENSE_NAME=	w3m
LICENSE_FILE=	${WRKSRC}/doc/README
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BROKEN_mips64=		fails to build: qemu: uncaught target signal 11 (Segmentation fault) - core dumped

LIB_DEPENDS=	libgc.so:devel/boehm-gc

USES=		iconv pkgconfig perl5 ssl
USE_GITHUB=	yes

GH_ACCOUNT=	tats
GH_PROJECT=	w3m
GH_TAGNAME=	aa078ed

MAKE_JOBS_UNSAFE=	yes
SNAPDATE=	20200507

CONFLICTS?=	ja-w3m-0.5.* ja-w3m-img-0.5.* w3m-img-0.5.*
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gc=${LOCALBASE} \
		ac_cv_path_PERL=${PERL}
CONFIGURE_ENV=	DEFS="-I${LOCALBASE}/include"

DOCS_COMMON=	FAQ.html HISTORY MANUAL.html README README.cookie \
		README.cygwin README.dict README.func README.img \
		README.m17n README.mouse README.passwd README.pre_form \
		README.siteconf README.tab STORY.html \
		keymap.default keymap.lynx menu.default menu.submenu
DOCS_DE=	FAQ.html MANUAL.html README.func
DOCS_EN=	README.sixel
DOCS_JP=	${DOCS_COMMON} README.SSL README.keymap \
		README.mailcap README.menu README.migemo

OPTIONS_DEFINE=	INLINE_IMAGE JAPANESE KEY_LYNX DOCS NLS
INLINE_IMAGE_DESC=	Inline image support
JAPANESE_DESC=		Japanese messages and migemo support
KEY_LYNX_DESC=		Keymap like lynx browser
OPTIONS_SUB=	yes

INLINE_IMAGE_USES=	gnome xorg
INLINE_IMAGE_USE=	xorg=x11 gnome=gtk20,gdkpixbuf2
INLINE_IMAGE_CONFIGURE_ON=	--with-imagelib=gtk2 --enable-image=fb,x11
INLINE_IMAGE_CONFIGURE_OFF=	--enable-image=no

JAPANESE_CONFIGURE_ON=	--enable-japanese=U --with-migemo=yes

KEY_LYNX_CONFIGURE_ON=	--with-keymap=lynx

NLS_USES=	gettext
NLS_CONFIGURE_ON=	--enable-nls
NLS_CONFIGURE_OFF=	--disable-nls

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MINLINE_IMAGE}
PKGMESSAGE=	${MASTERDIR}/pkg-message
CONFIGURE_ENV += LDFLAGS="-L${LOCALBASE}/lib" LIBS="-lX11"
.else
# Don't use pkg-message
PKGMESSAGE=	${NONEXISTENT}
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|`\(expr\) \(.*\) : \(.*\)`|`\1 \\( \2 : \3 \\)`|' \
		-e 's|/usr/local|${LOCALBASE}|g' \
		${WRKSRC}/configure
	@${FIND} ${WRKSRC}/doc* -type f \! -name HISTORY \
		-exec ${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|g' {} +
	@${CP} ${WRKSRC}/scripts/w3mhelp-funcdesc.ja.pl.in \
		${WRKSRC}/scripts/w3mhelp-funcdesc.ja.pl.in.bak
	@${ICONV_CMD} -f EUC-JP -t UTF-8 \
		${WRKSRC}/scripts/w3mhelp-funcdesc.ja.pl.in.bak \
		> ${WRKSRC}/scripts/w3mhelp-funcdesc.ja.pl.in
	@${REINPLACE_CMD} -e 's|EUC-JP|UTF-8|g' \
		${WRKSRC}/scripts/w3mhelp-funcdesc.ja.pl.in

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/doc/ja/w3m
	@cd ${WRKSRC}/doc-jp; \
	for i in ${DOCS_JP} ; do \
		${INSTALL_DATA} $$i ${STAGEDIR}${PREFIX}/share/doc/ja/w3m/ ; \
	done
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/doc/de/w3m
	@cd ${WRKSRC}/doc-de; \
	for i in ${DOCS_DE} ; do \
		${INSTALL_DATA} $$i ${STAGEDIR}${PREFIX}/share/doc/de/w3m/ ; \
	done
	@cd ${WRKSRC}/doc; \
	${MKDIR} ${STAGEDIR}${PREFIX}/share/doc/w3m/; \
	for i in ${DOCS_COMMON} ${DOCS_EN} ; do \
		${INSTALL_DATA} $$i ${STAGEDIR}${PREFIX}/share/doc/w3m/ ; \
	done
	${INSTALL_MAN} ${WRKSRC}/scripts/w3mman/w3mman.1 ${STAGEDIR}${PREFIX}/man/ja/man1

.include <bsd.port.mk>
