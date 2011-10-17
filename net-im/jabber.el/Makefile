# New ports collection makefile for:    jabber.el
# Date created:                         26 May 2006
# Whom:                                 Max N. Boyarov <m.boyarov@bsd.by>
#
# $FreeBSD$

PORTNAME=	jabber.el
PORTVERSION=	0.8.0
PORTREVISION=	7
CATEGORIES=	net-im elisp
MASTER_SITES=	SF/emacs-jabber/emacs-jabber/${PORTVERSION}
DISTNAME=		emacs-jabber-${PORTVERSION}

MAINTAINER=	m.boyarov@gmail.com
COMMENT=	A minimal jabber client for [X]Emacs

RUN_DEPENDS=	${LOCALBASE}/bin/gnutls-cli:${PORTSDIR}/security/gnutls

INFO=		emacs-jabber
PORTDOCS+=	AUTHORS NEWS README

USE_EMACS=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

.include <bsd.port.pre.mk>

CONFIGURE_ARGS+=	--with-lispdir=${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/emacs-jabber \
			--disable-schemas-install

pre-configure:
	${REINPLACE_CMD} -e 's/jabber\.info/emacs-jabber.info/' \
		${WRKSRC}/Makefile.in

	( cd ${WRKSRC} && ${CP} -f jabber.info emacs-jabber.info )
	${REINPLACE_CMD} -e 's/^File: jabber.info/File: emacs-jabber.info/'	\
			-e 's/^* jabber.el: (jabber)/* jabber.el: (emacs-jabber)/'	\
			${WRKSRC}/emacs-jabber.info

pre-install:
	${MKDIR} ${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/emacs-jabber

post-install:
.if !defined(NOPORTDOCS)
		${MKDIR} ${DOCSDIR}
.for doc in ${PORTDOCS}
		${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}/
.endfor
.endif

.include <bsd.port.post.mk>
