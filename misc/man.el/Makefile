# New ports collection makefile for:	man.el with I18N
# Date created:		10 September 1998
# Whom:			KIRIYAMA Kazuhiko <kiri@kiri.toba-cmt.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	i18n-man
PORTVERSION=	1.1
CATEGORIES=	misc elisp
MASTER_SITES=	ftp://daemon.jp.freebsd.org/pub/FreeBSD-jp/man-jp/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Browse I18N capable UNIX manual pages with Mule, Emacs and XEmacs

# If you use Japanese manuals, install japanese/man as well.

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

ELISPDIR=	${PREFIX}/share/emacs/site-lisp
SITEPKGDIR=	${PREFIX}/lib/xemacs/site-packages
PKGMODULES=	i18n-man-de i18n-man-en i18n-man-ja

do-install:
	@${MKDIR} ${ELISPDIR} ${PREFIX}/share/doc/i18n-man
	@cd ${WRKSRC}; \
	${INSTALL_DATA} `${TAR} tzf ${DISTDIR}/${DISTFILES}` ${ELISPDIR}
# For xemacs package install configuration
	${MKDIR}  ${SITEPKGDIR}/pkginfo
.for f in ${PKGMODULES}
	${MKDIR} ${SITEPKGDIR}/lisp/${f}
	${LN} -sf ${ELISPDIR}/${f}.el ${SITEPKGDIR}/lisp/${f}/${f}.el
	${LN} -sf ${ELISPDIR}/i18n-man.el ${SITEPKGDIR}/lisp/${f}/i18n-man.el
	${ECHO_CMD} "pkginfo/MANIFEST.${f}" > ${SITEPKGDIR}/pkginfo/MANIFEST.${f}
	${ECHO_CMD} "lisp/${f}/${f}.el" >> ${SITEPKGDIR}/pkginfo/MANIFEST.${f}
	${ECHO_CMD} "lisp/${f}/i18n-man.el" >> ${SITEPKGDIR}/pkginfo/MANIFEST.${f}
.endfor
	${INSTALL_SCRIPT} ${FILESDIR}/byte-compile ${PREFIX}/share/doc/i18n-man

.include <bsd.port.mk>
