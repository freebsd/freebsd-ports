# Created by: Max N. Boyarov <m.boyarov@bsd.by>
# $FreeBSD$

PORTNAME=	jabber.el
PORTVERSION=	0.8.92
PORTREVISION=	3
CATEGORIES=	net-im elisp
MASTER_SITES=	SF/emacs-jabber/emacs-jabber%20beta%20versions/${PORTVERSION}
DISTNAME=		emacs-jabber-${PORTVERSION}

MAINTAINER=	max.n.boyarov@gmail.com
COMMENT=	Minimal jabber client for [X]Emacs

RUN_DEPENDS=	${LOCALBASE}/bin/gnutls-cli:security/gnutls

INFO=		emacs-jabber
PORTDOCS+=	AUTHORS NEWS README

USE_EMACS=	yes
GNU_CONFIGURE=	yes
USES=		gmake

OPTIONS_DEFINE=	DOCS

CONFIGURE_ARGS+=	--with-lispdir=${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/emacs-jabber \
			--disable-schemas-install

.include <bsd.port.options.mk>

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
