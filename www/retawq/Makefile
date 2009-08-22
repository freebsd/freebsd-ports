# ex:ts=8
# Ports collection makefile for:	retawq
# Date created:			Dec 30, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	retawq
DISTVERSION=	0.2.6c
PORTREVISION=	6
CATEGORIES=	www ipv6
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-0.2.6c

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An interactive, multi-threaded web browser for text terminals

USE_GETTEXT=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--path-archprefix=${PREFIX} --path-prefix=${PREFIX} \
		--enable-i18n --enable-local-cgi --enable-ipv6

MAN1=		retawq.1
PLIST_FILES=	bin/retawq \
		share/locale/de/LC_MESSAGES/retawq.mo \
		share/locale/es/LC_MESSAGES/retawq.mo \
		share/locale/fr/LC_MESSAGES/retawq.mo \
		share/locale/pt_BR/LC_MESSAGES/retawq.mo
PORTDOCS=	*

CPPFLAGS=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

.if defined(WITH_GNUTLS)
LIB_DEPENDS+=	gnutls.40:${PORTSDIR}/security/gnutls
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
	@${INSTALL_PROGRAM} ${WRKSRC}/retawq ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/docu/retawq.1 ${MANPREFIX}/man/man1
.for lang in de es fr pt_BR
	@${MKDIR} ${PREFIX}/share/locale/${lang}/LC_MESSAGES
	@${INSTALL_DATA} ${WRKSRC}/i18n/${lang}.mo \
		${PREFIX}/share/locale/${lang}/LC_MESSAGES/${PORTNAME}.mo
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/docu/*.html ${DOCSDIR}
.endif

.include <bsd.port.mk>
