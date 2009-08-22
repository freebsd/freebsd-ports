# New ports collection makefile for:    jabber.el
# Date created:                         26 May 2006
# Whom:                                 Max N. Boyarov <m.boyarov@bsd.by>
#
# $FreeBSD$

PORTNAME=	jabber.el
PORTVERSION=	0.7.1
CATEGORIES=	net-im elisp
MASTER_SITES=	SF/emacs-jabber/emacs-jabber/${PORTVERSION}
DISTNAME=		emacs-jabber-${PORTVERSION}

MAINTAINER=	m.boyarov@bsd.by
COMMENT=	A minimal jabber client for [X]Emacs

NO_BUILD=	yes

INFO=		jabber.el
PORTDOCS+=	AUTHORS NEWS README

EMACS_LISPDIR=	share/emacs/site-lisp/emacs-jabber
XEMACS_LISPDIR=	lib/xemacs/site-lisp/emacs-jabber

PLIST_SUB+=	EMACS_LISPDIR=${EMACS_LISPDIR}	\
		XEMACS_LISPDIR=${XEMACS_LISPDIR}

## Generate info
pre-install:
	( cd ${WRKSRC} && ${CP} -f jabber.info jabber.el.info )
	${REINPLACE_CMD} -e 's/^File: jabber.info/File: jabber.el.info/'	\
			-e 's/^* jabber.el: (jabber)/* jabber.el: (jabber.el)/'	\
			${WRKSRC}/jabber.el.info

do-install:
	${MKDIR} ${PREFIX}/${EMACS_LISPDIR}
	${MKDIR} ${PREFIX}/${XEMACS_LISPDIR}
	cd ${WRKSRC}; \
	for el in `ls -1 *.el`; do							\
		${INSTALL_DATA} $$el ${PREFIX}/${EMACS_LISPDIR}/;			\
		${LN} -sf ${PREFIX}/${EMACS_LISPDIR}/$$el ${PREFIX}/${XEMACS_LISPDIR}/;	\
	done;

	${INSTALL_DATA} ${WRKSRC}/${INFO}.info ${PREFIX}/${INFO_PATH}/
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/xmppuri.sh ${EXAMPLESDIR}/

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}/
.endfor
.endif

.include <bsd.port.mk>
