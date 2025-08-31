PORTNAME=	w3m
DISTVERSIONPREFIX=	v
DISTVERSION=	0.5.5
CATEGORIES+=	www
MASTER_SITES=	https://git.sr.ht/~rkta/${PORTNAME}/archive/${DISTVERSIONFULL}${EXTRACT_SUFX}?dummy=/

MAINTAINER?=	nobutaka@FreeBSD.org
COMMENT?=	Pager/text-based WWW browser
WWW=		https://git.sr.ht/~rkta/w3m

LICENSE=	w3m
LICENSE_NAME=	w3m
LICENSE_FILE=	${WRKSRC}/doc/README
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BROKEN_mips64=		fails to build: qemu: uncaught target signal 11 (Segmentation fault) - core dumped

LIB_DEPENDS=	libgc.so:devel/boehm-gc

USES=		cpe iconv pkgconfig perl5 ssl

CPE_VENDOR=	w3m_project

MAKE_JOBS_UNSAFE=	yes

CONFLICTS?=	ja-w3m-0.5.* ja-w3m-img-0.5.* w3m-img-0.5.*
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS=	--with-gc=${LOCALBASE} \
		ac_cv_path_PERL=${PERL}
CONFIGURE_ENV=	DEFS="-I${LOCALBASE}/include"

DOCS_COMMON=	FAQ.html HISTORY MANUAL.html README README.SSL \
		README.cookie README.cygwin README.dict README.func \
		README.img README.keymap README.menu README.m17n \
		README.mouse README.passwd README.pre_form \
		README.siteconf README.tab STORY.html \
		keymap.default keymap.lynx menu.default menu.submenu
DOCS_DE=	FAQ.html MANUAL.html README.func
DOCS_JP=	${DOCS_COMMON} README.mailcap README.menu README.migemo

OPTIONS_DEFINE=	INLINE_IMAGE JAPANESE KEY_LYNX DOCS NLS
INLINE_IMAGE_DESC=	Inline image support
JAPANESE_DESC=		Japanese messages and migemo support
KEY_LYNX_DESC=		Keymap like lynx browser
OPTIONS_SUB=	yes

INLINE_IMAGE_USES=	xorg
INLINE_IMAGE_USE=	xorg=x11
INLINE_IMAGE_LIB_DEPENDS=	libImlib2.so:graphics/imlib2
INLINE_IMAGE_CONFIGURE_ON=	--with-imagelib=imlib2 --enable-image=fb,x11
INLINE_IMAGE_CONFIGURE_OFF=	--enable-image=fb

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
	for i in ${DOCS_COMMON} ; do \
		${INSTALL_DATA} $$i ${STAGEDIR}${PREFIX}/share/doc/w3m/ ; \
	done
	${MKDIR} ${STAGEDIR}${PREFIX}/share/man/ja/man1
	${INSTALL_MAN} ${WRKSRC}/scripts/w3mman/w3mman.1 ${STAGEDIR}${PREFIX}/share/man/ja/man1

.include <bsd.port.mk>
