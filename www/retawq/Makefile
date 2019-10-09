# Created by: ijliao
# $FreeBSD$

PORTNAME=	retawq
DISTVERSION=	0.2.6c
PORTREVISION=	11
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-0.2.6c

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Interactive, multi-threaded web browser for text terminals

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gettext localbase ncurses
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--path-archprefix=${PREFIX} --path-prefix=${PREFIX} \
		--enable-i18n --enable-local-cgi --enable-ipv6

PLIST_FILES=	bin/retawq \
		man/man1/retawq.1.gz \
		share/locale/de/LC_MESSAGES/retawq.mo \
		share/locale/es/LC_MESSAGES/retawq.mo \
		share/locale/fr/LC_MESSAGES/retawq.mo \
		share/locale/pt_BR/LC_MESSAGES/retawq.mo
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS
OPTIONS_RADIO=	BACKEND
OPTIONS_RADIO_BACKEND=	OPENSSL GNUTLS

BACKEND_DESC=	SSL Backend

GNUTLS_LIB_DEPENDS=	libgnutls.so:security/gnutls
GNUTLS_CONFIGURE_ON=	--set-tls=1

OPENSSL_USES=		ssl
OPENSSL_CONFIGURE_ON=	--set-tls=2
OPENSSL_LDFLAGS=	-lssl -lcrypto

post-configure:
	${REINPLACE_CMD} -e 's|_IN_H 0|_IN_H 1|g ; \
		 s|_SOCKET_H 0|_SOCKET_H 1|g' ${WRKSRC}/.config

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/retawq ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/docu/retawq.1 ${STAGEDIR}${MANPREFIX}/man/man1
.for lang in de es fr pt_BR
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/locale/${lang}/LC_MESSAGES
	${INSTALL_DATA} ${WRKSRC}/i18n/${lang}.mo \
		${STAGEDIR}${PREFIX}/share/locale/${lang}/LC_MESSAGES/${PORTNAME}.mo
.endfor

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docu/*.html ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
