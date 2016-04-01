# Created by: KIRIYAMA Kazuhiko<kiri@pis.toba-cmt.ac.jp>
# $FreeBSD$

PORTNAME=	prom-wl
PORTVERSION=	2.7.0
PORTREVISION=	1
CATEGORIES=	mail elisp
MASTER_SITES=	http://www.h6.dion.ne.jp/~nytheta/software/pub/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Procmail reader for Wanderlust on GNU Emacs

# This port requires Wanderlust. But we can't decide which Wanderlust to
# depends, there is NO RUN_DEPENDS mail/wanderlust-*.
#RUN_DEPENDS=	procmail:mail/procmail

NO_BUILD=	yes

ELISPDIR=	${PREFIX}/share/emacs/site-lisp
SITEPKGDIR=	${PREFIX}/lib/xemacs/site-packages

OPTIONS_DEFINE=	DOCS EXAMPLES

do-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}; ${INSTALL_DATA} ChangeLog prom-wl-usage.jis \
		${STAGEDIR}${DOCSDIR})
	(cd ${FILESDIR}; ${INSTALL_SCRIPT} byte-compile ${STAGEDIR}${DOCSDIR})
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${FILESDIR} ; ${INSTALL_DATA} dot.emacs dot.procmailrc \
		${STAGEDIR}${EXAMPLESDIR})
	@${MKDIR} ${STAGEDIR}${ELISPDIR}
	(cd ${WRKSRC}; ${INSTALL_DATA} prom-wl.el ${STAGEDIR}${ELISPDIR})

# For xemacs package install configuration
	@${MKDIR} ${STAGEDIR}${SITEPKGDIR}/lisp/prom-wl
	@${MKDIR} ${STAGEDIR}${SITEPKGDIR}/pkginfo
	@${LN} -sf ${ELISPDIR}/prom-wl.el \
		${STAGEDIR}${SITEPKGDIR}/lisp/prom-wl/prom-wl.el
	@${ECHO_CMD} 'pkginfo/MANIFEST.prom-wl' > \
		${STAGEDIR}${SITEPKGDIR}/pkginfo/MANIFEST.prom-wl
	@${ECHO_CMD} 'lisp/prom-wl/prom-wl.el' >> \
		${STAGEDIR}${SITEPKGDIR}/pkginfo/MANIFEST.prom-wl

.include <bsd.port.mk>
