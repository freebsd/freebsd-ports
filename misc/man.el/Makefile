# Created by: KIRIYAMA Kazuhiko <kiri@kiri.toba-cmt.ac.jp>
# $FreeBSD$

PORTNAME=	i18n-man
PORTVERSION=	1.1
CATEGORIES=	misc elisp
MASTER_SITES=	ftp://daemon.jp.freebsd.org/pub/FreeBSD-jp/man-jp/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Browse I18N capable UNIX manual pages with Mule, Emacs, and XEmacs

# If you use Japanese manuals, install japanese/man as well.

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

ELISPDIR=	${PREFIX}/share/emacs/site-lisp
SITEPKGDIR=	${PREFIX}/lib/xemacs/site-packages
PKGMODULES=	i18n-man-de i18n-man-en i18n-man-ja

do-install:
	@${MKDIR} ${STAGEDIR}${ELISPDIR} ${STAGEDIR}${PREFIX}/share/doc/i18n-man
	@cd ${WRKSRC}; \
	${INSTALL_DATA} `${TAR} tzf ${DISTDIR}/${DISTFILES}` \
		${STAGEDIR}${ELISPDIR}
# For xemacs package install configuration
	@${MKDIR} ${STAGEDIR}${SITEPKGDIR}/pkginfo
.for f in ${PKGMODULES}
	@${MKDIR} ${STAGEDIR}${SITEPKGDIR}/lisp/${f}
	${LN} -sf ${ELISPDIR}/${f}.el ${STAGEDIR}${SITEPKGDIR}/lisp/${f}/${f}.el
	${LN} -sf ${ELISPDIR}/i18n-man.el \
		${STAGEDIR}${SITEPKGDIR}/lisp/${f}/i18n-man.el
	${ECHO_CMD} "pkginfo/MANIFEST.${f}" > \
		${STAGEDIR}${SITEPKGDIR}/pkginfo/MANIFEST.${f}
	${ECHO_CMD} "lisp/${f}/${f}.el" >> \
		${STAGEDIR}${SITEPKGDIR}/pkginfo/MANIFEST.${f}
	${ECHO_CMD} "lisp/${f}/i18n-man.el" >> \
		${STAGEDIR}${SITEPKGDIR}/pkginfo/MANIFEST.${f}
.endfor
	${INSTALL_SCRIPT} ${FILESDIR}/byte-compile \
		${STAGEDIR}${PREFIX}/share/doc/i18n-man

.include <bsd.port.mk>
