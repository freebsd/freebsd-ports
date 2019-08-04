# Created by: KIRIYAMA Kazuhiko<kiri@pis.toba-cmt.ac.jp>
# $FreeBSD$

PORTNAME=	prom-wl
PORTVERSION=	2.7.0
PORTREVISION=	2
CATEGORIES=	mail elisp
MASTER_SITES=	http://www.h6.dion.ne.jp/~nytheta/software/pub/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Procmail reader for Wanderlust on GNU Emacs

LICENSE=	GPLv2+

BROKEN=		unfetchable

# This port requires Wanderlust. But we can't decide which Wanderlust to
# depends, there is NO RUN_DEPENDS mail/wanderlust-*.
#RUN_DEPENDS=	procmail:mail/procmail

NO_BUILD=	yes
NO_ARCH=	yes

ELISPDIR=	${PREFIX}/share/emacs/site-lisp

OPTIONS_DEFINE=	DOCS EXAMPLES

do-install:
	@${MKDIR} ${STAGEDIR}${ELISPDIR}
	(cd ${WRKSRC}; ${INSTALL_DATA} prom-wl.el ${STAGEDIR}${ELISPDIR})

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${WRKSRC}/prom-wl-usage.jis \
		${STAGEDIR}${DOCSDIR}
	${INSTALL_SCRIPT} ${FILESDIR}/byte-compile ${STAGEDIR}${DOCSDIR}

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${FILESDIR}/dot.emacs ${FILESDIR}/dot.procmailrc \
		${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
