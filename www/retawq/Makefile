# Created by: ijliao
# $FreeBSD$

PORTNAME=	retawq
DISTVERSION=	0.2.6c
PORTREVISION=	9
CATEGORIES=	www ipv6
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-0.2.6c

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An interactive, multi-threaded web browser for text terminals

USES=		gettext
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

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -pthread

.if defined(WITH_GNUTLS)
LIB_DEPENDS+=	libgnutls.so:${PORTSDIR}/security/gnutls
CONFIGURE_ARGS+=	--set-tls=1
.elif defined(WITH_OPENSSL)
USE_OPENSSL=	yes
CONFIGURE_ARGS+=	--set-tls=2
LDFLAGS+=	-lssl -lcrypto
.endif

post-configure:
	@${REINPLACE_CMD} -e 's|_IN_H 0|_IN_H 1|g ; \
		 s|_SOCKET_H 0|_SOCKET_H 1|g' ${WRKSRC}/.config

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/retawq ${STAGEDIR}${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/docu/retawq.1 ${STAGEDIR}${MANPREFIX}/man/man1
.for lang in de es fr pt_BR
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/locale/${lang}/LC_MESSAGES
	@${INSTALL_DATA} ${WRKSRC}/i18n/${lang}.mo \
		${STAGEDIR}${PREFIX}/share/locale/${lang}/LC_MESSAGES/${PORTNAME}.mo
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/docu/*.html ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
