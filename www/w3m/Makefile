# Created by: MANTANI Nobutaka <nobutaka@nobutaka.com>
# $FreeBSD$

PORTNAME=	w3m
PORTVERSION=	0.5.3
PORTREVISION=	5
CATEGORIES+=	www ipv6
MASTER_SITES=	SF/w3m/w3m/w3m-${PORTVERSION}

MAINTAINER?=	nobutaka@FreeBSD.org
COMMENT?=	Pager/text-based WWW browser

USES=		pkgconfig perl5
USE_OPENSSL=	yes
LIB_DEPENDS=	libgc.so:devel/boehm-gc

MAKE_JOBS_UNSAFE=	yes

CONFLICTS?=	ja-w3m-0.5.* ja-w3m-img-0.5.* w3m-img-0.5.*
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gc=${LOCALBASE} \
		ac_cv_path_PERL=${PERL}
CONFIGURE_ENV=	DEFS="-I${LOCALBASE}/include"


DOCS=		FAQ.html HISTORY MANUAL.html README \
		README.dict README.func README.img README.m17n STORY.html \
		keymap.default keymap.lynx menu.default menu.submenu
DOCS_JP=	${DOCS} README.SSL README.cookie README.keymap README.img \
		README.mailcap README.menu README.migemo

OPTIONS_DEFINE=	JAPANESE INLINE_IMAGE KEY_LYNX DOCS
JAPANESE_DESC=		Japanese messages and migemo support
INLINE_IMAGE_DESC=	Inline image support
KEY_LYNX_DESC=		Keymap like lynx browser
OPTIONS_SUB=	yes

JAPANESE_USES=	gettext
JAPANESE_CONFIGURE_ON=	--enable-japanese=E --with-migemo=yes gt_cv_func_gnugettext1_libintl=yes
JAPANESE_CONFIGURE_ENABLE=	nls

INLINE_IMAGE_USE=	gnome=gtk20
INLINE_IMAGE_CONFIGURE_ON=	--with-imagelib=gtk2 --enable-image=fb,x11
INLINE_IMAGE_CONFIGURE_OFF=	--enable-image=no

KEY_LYNX_CONFIGURE_ON=	--with-keymap=lynx

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
		's|\`\(expr\) \(.*\) : \(.*\)`|`\1 \\( \2 : \3 \\)`|' \
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
	@cd ${WRKSRC}/doc; \
	${MKDIR} ${STAGEDIR}${PREFIX}/share/doc/w3m/; \
	for i in ${DOCS} ; do \
		${INSTALL_DATA} $$i ${STAGEDIR}${PREFIX}/share/doc/w3m/ ; \
	done
	@${INSTALL_MAN} ${WRKSRC}/scripts/w3mman/w3mman.1 ${STAGEDIR}${PREFIX}/man/ja/man1

.include <bsd.port.mk>
