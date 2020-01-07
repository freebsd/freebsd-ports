# Created by: Max N. Boyarov <m.boyarov@bsd.by>
# $FreeBSD$

PORTNAME=	jabber.el
PORTVERSION=	0.8.92
PORTREVISION=	10
CATEGORIES=	net-im elisp
MASTER_SITES=	SF/emacs-jabber/emacs-jabber%20beta%20versions/${PORTVERSION}
PKGNAMESUFFIX=	${EMACS_PKGNAMESUFFIX}
DISTNAME=		emacs-jabber-${PORTVERSION}

MAINTAINER=	max.n.boyarov@gmail.com
COMMENT=	Minimal jabber client for [X]Emacs

.if ${FLAVOR:U} != devel && ${FLAVOR:U} != devel_nox
# http://pkg.awarnach.mathstat.dal.ca/data/11i386-default/2018-05-30_07h36m11s/logs/errors/jabber.el-emacs26-0.8.92_7.log
BROKEN=		fails to build
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
