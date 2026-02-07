PORTNAME=	emacs-libvterm
DISTVERSION=	g20251119
CATEGORIES=	misc elisp
PKGNAMESUFFIX=	${EMACS_PKGNAMESUFFIX}

MAINTAINER=	tslight@pm.me
COMMENT=	Emacs libvterm integration

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libvterm.so:devel/libvterm

USES=		cmake:noninja emacs

USE_GITHUB=	yes
GH_ACCOUNT=	akermu
GH_TAGNAME=	a01a2894a1c1e81a39527835a9169e35b7ec5dec

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}/etc
	@${MKDIR} ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}/vterm
	${INSTALL_DATA} ${WRKSRC}/vterm.el \
		${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}/vterm
	${INSTALL_LIB} ${WRKSRC}/vterm-module.so \
		${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}/vterm
	${INSTALL_DATA} ${WRKSRC}/etc/emacs-vterm-bash.sh \
		${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}/etc/
	${INSTALL_DATA} ${WRKSRC}/etc/emacs-vterm-zsh.sh \
		${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}/etc/
	${INSTALL_DATA} ${WRKSRC}/etc/emacs-vterm.fish \
		${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}/etc/

.include <bsd.port.mk>
