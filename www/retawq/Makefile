# ex:ts=8
# Ports collection makefile for:	retawq
# Date created:			Dec 30, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	retawq
PORTVERSION=	0.1.7
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An interactive, multi-threaded web browser for text terminals

LIB_DEPENDS=	intl.5:${PORTSDIR}/devel/gettext-old

USE_REINPLACE=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--path-archprefix=${PREFIX} --path-prefix=${PREFIX} \
		--enable-i18n --enable-local-cgi --enable-ipv6

MAN1=		retawq.1

CPPFLAGS=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

.if defined(WITH_GNUTLS)
LIB_DEPENDS+=	gnutls.7:${PORTSDIR}/security/gnutls
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
	${INSTALL_PROGRAM} ${WRKSRC}/retawq ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/docu/retawq.1 ${MANPREFIX}/man/man1
.for lang in de es fr pt_BR
	${INSTALL_DATA} ${WRKSRC}/i18n/${lang}.mo \
		${PREFIX}/share/locale/${lang}/LC_MESSAGES/${PORTNAME}.mo
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docu/*.html ${DOCSDIR}
.endif

.include <bsd.port.mk>
