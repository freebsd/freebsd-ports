# Created by: Max N. Boyarov <m.boyarov@bsd.by>

PORTNAME=	jabber.el
PORTVERSION=	0.8.92
PORTREVISION=	12
CATEGORIES=	net-im elisp
MASTER_SITES=	SF/emacs-jabber/emacs-jabber%20beta%20versions/${PORTVERSION}
PKGNAMESUFFIX=	${EMACS_PKGNAMESUFFIX}
DISTNAME=		emacs-jabber-${PORTVERSION}

MAINTAINER=	max.n.boyarov@gmail.com
COMMENT=	Minimal jabber client for [X]Emacs

.if ${FLAVOR:U} == devel_full || ${FLAVOR:U} == devel_nox
BROKEN=		Debugger entered--Lisp error: (wrong-type-argument stringp nil)
.endif

RUN_DEPENDS=	${LOCALBASE}/bin/gnutls-cli:security/gnutls

USES=		emacs gmake
GNU_CONFIGURE=	yes

INFO=		emacs-jabber
PORTDOCS=	AUTHORS NEWS README

CONFIGURE_ARGS=	--with-lispdir=${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/emacs-jabber \
		--disable-schemas-install

OPTIONS_DEFINE=	DOCS

pre-configure:
	${REINPLACE_CMD} -e 's/jabber\.info/emacs-jabber.info/' \
		${WRKSRC}/Makefile.in

	( cd ${WRKSRC} && ${CP} -f jabber.info emacs-jabber.info )
	${REINPLACE_CMD} -e 's/^File: jabber.info/File: emacs-jabber.info/'	\
			-e 's/^* jabber.el: (jabber)/* jabber.el: (emacs-jabber)/'	\
			${WRKSRC}/emacs-jabber.info

pre-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/emacs-jabber

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in ${PORTDOCS}
		${INSTALL_DATA} ${WRKSRC}/${doc} ${STAGEDIR}${DOCSDIR}/
.endfor

.include <bsd.port.mk>
