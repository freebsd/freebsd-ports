# New ports collection makefile for:	prom-mew
# Date created:		28 Jun 1999
# Whom:			KIRIYAMA Kazuhiko<kiri@pis.toba-cmt.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	prom-mew
PORTVERSION=	1.93.4
PORTREVISION=	1
CATEGORIES=	mail elisp
MASTER_SITES=	http://www02.so-net.ne.jp/~murata/software/pub/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Procmail reader for Mew on GNU Emacs

# This port requires Mew. But we can't decide which mew to depends, there is
# NO RUN_DEPENDS mail/mew*.
RUN_DEPENDS=	procmail:${PORTSDIR}/mail/procmail

NO_BUILD=	yes

ELISPDIR=	${PREFIX}/share/emacs/site-lisp
SITEPKGDIR=	${PREFIX}/lib/xemacs/site-packages

do-install:
	@${MKDIR} ${ELISPDIR} ${PREFIX}/share/doc/prom-mew \
		${PREFIX}/share/examples/prom-mew
	@cd ${WRKSRC}; \
	${INSTALL_DATA} prom-mew.el ${ELISPDIR}; \
	${INSTALL_DATA} ChangeLog prom-usage.jis ${PREFIX}/share/doc/prom-mew
	@cd ${FILESDIR}; \
	${INSTALL_SCRIPT} byte-compile ${PREFIX}/share/doc/prom-mew; \
	${INSTALL_DATA} dot.emacs dot.procmailrc ${PREFIX}/share/examples/prom-mew
# For xemacs package install configuration
	@${MKDIR} ${SITEPKGDIR}/lisp/prom-mew ${SITEPKGDIR}/pkginfo
	@${LN} -sf ${ELISPDIR}/prom-mew.el ${SITEPKGDIR}/lisp/prom-mew/prom-mew.el
	@${ECHO_CMD} 'pkginfo/MANIFEST.prom-mew' > ${SITEPKGDIR}/pkginfo/MANIFEST.prom-mew
	@${ECHO_CMD} 'lisp/prom-mew/prom-mew.el' >> ${SITEPKGDIR}/pkginfo/MANIFEST.prom-mew

.include <bsd.port.mk>
