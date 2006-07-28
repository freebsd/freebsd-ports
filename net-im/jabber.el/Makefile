# New ports collection makefile for:    jabber.el
# Date created:                         26 May 2006
# Whom:                                 Max N. Boyarov <m.boyarov@bsd.by>
#
# $FreeBSD$

PORTNAME=	jabber.el
PORTVERSION=	0.7
PORTREVISION=	1
CATEGORIES=	net-im elisp
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	emacs-jabber
DISTNAME=		emacs-jabber-${PORTVERSION}

MAINTAINER=	m.boyarov@bsd.by
COMMENT=	A minimal jabber client for [X]Emacs

NO_BUILD=	yes

INFO=		jabber.el
PORTDOCS+=	AUTHORS NEWS README filetransfer.txt

EMACS_LISPDIR=	${PREFIX}/share/emacs/site-lisp/emacs-jabber
XEMACS_LISPDIR=	${PREFIX}/lib/xemacs/site-lisp/emacs-jabber

## Generate info
pre-install:
	${REINPLACE_CMD} -e 's/^@setfilename jabber.info/@setfilename jabber.el.info/' 	\
			-e 's/\* jabber\.el: (jabber)\./* jabber.el: (jabber.el)./'	\
		${WRKSRC}/jabber.texi
	( cd ${WRKSRC}; makeinfo --no-split jabber.texi; )

do-install:
	${MKDIR} ${EMACS_LISPDIR}
	${MKDIR} ${XEMACS_LISPDIR}
	cd ${WRKSRC}; \
	for el in `ls -1 *.el`; do					\
		${INSTALL_DATA} $$el ${EMACS_LISPDIR}/;			\
		${LN} -sf ${EMACS_LISPDIR}/$$el ${XEMACS_LISPDIR}/;	\
	done;

	${INSTALL_DATA} ${WRKSRC}/${INFO}.info ${PREFIX}/${INFO_PATH}/

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}/
.endfor
.endif

.include <bsd.port.mk>
