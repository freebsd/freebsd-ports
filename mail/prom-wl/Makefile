# New ports collection makefile for:	prom-wl
# Date created:		28 Aug 1999
# Whom:			KIRIYAMA Kazuhiko<kiri@pis.toba-cmt.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	prom-wl
PORTVERSION=	1.1.2
PORTREVISION=	1
CATEGORIES=	mail elisp
MASTER_SITES=	http://www02.so-net.ne.jp/~murata/software/pub/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Procmail reader for Wanderlust on GNU Emacs

# This port requires Wanderlust. But we can't decide which Wanderlust to
# depends, there is NO RUN_DEPENDS mail/wanderlust-*.
RUN_DEPENDS=	procmail:${PORTSDIR}/mail/procmail

NO_BUILD=	yes

ELISPDIR=	${PREFIX}/share/emacs/site-lisp
SITEPKGDIR=	${PREFIX}/lib/xemacs/site-packages

do-install:
	@${MKDIR} ${ELISPDIR} ${PREFIX}/share/doc/prom-wl \
		${PREFIX}/share/examples/prom-wl
	@cd ${WRKSRC}; \
	${INSTALL_DATA} prom-wl.el ${ELISPDIR}; \
	${INSTALL_DATA} ChangeLog prom-wl-usage.jis ${PREFIX}/share/doc/prom-wl
	@cd ${FILESDIR}; \
	${INSTALL_SCRIPT} byte-compile ${PREFIX}/share/doc/prom-wl; \
	${INSTALL_DATA} dot.emacs dot.procmailrc ${PREFIX}/share/examples/prom-wl
# For xemacs package install configuration
	@${MKDIR} ${SITEPKGDIR}/lisp/prom-wl ${SITEPKGDIR}/pkginfo
	@${LN} -sf ${ELISPDIR}/prom-wl.el ${SITEPKGDIR}/lisp/prom-wl/prom-wl.el
	@${ECHO_CMD} 'pkginfo/MANIFEST.prom-wl' > ${SITEPKGDIR}/pkginfo/MANIFEST.prom-wl
	@${ECHO_CMD} 'lisp/prom-wl/prom-wl.el' >> ${SITEPKGDIR}/pkginfo/MANIFEST.prom-wl

.include <bsd.port.mk>
