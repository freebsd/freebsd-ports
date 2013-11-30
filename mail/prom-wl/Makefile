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
#RUN_DEPENDS=	procmail:${PORTSDIR}/mail/procmail

NO_BUILD=	yes

ELISPDIR=	${PREFIX}/share/emacs/site-lisp
SITEPKGDIR=	${PREFIX}/lib/xemacs/site-packages

NO_STAGE=	yes
do-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@(cd ${WRKSRC}; ${INSTALL_DATA} ChangeLog \
					prom-wl-usage.jis \
					${DOCSDIR}/)
	@(cd ${FILESDIR}; ${INSTALL_SCRIPT} byte-compile ${DOCSDIR}/)
.endif

.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	@(cd ${FILESDIR} ; ${INSTALL_DATA} dot.emacs dot.procmailrc \
					${EXAMPLESDIR}/)
.endif

	@${MKDIR} ${ELISPDIR}
	@(cd ${WRKSRC}; ${INSTALL_DATA} prom-wl.el ${ELISPDIR}/)

# For xemacs package install configuration
	@${MKDIR} ${SITEPKGDIR}/lisp/prom-wl ${SITEPKGDIR}/pkginfo
	@${LN} -sf ${ELISPDIR}/prom-wl.el ${SITEPKGDIR}/lisp/prom-wl/prom-wl.el
	@${ECHO_CMD} 'pkginfo/MANIFEST.prom-wl' > ${SITEPKGDIR}/pkginfo/MANIFEST.prom-wl
	@${ECHO_CMD} 'lisp/prom-wl/prom-wl.el' >> ${SITEPKGDIR}/pkginfo/MANIFEST.prom-wl

.include <bsd.port.mk>
