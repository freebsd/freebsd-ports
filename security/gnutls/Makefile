# New ports collection makefile for:	gnutls
# Date created:		13 Nov 2002
# Whom:			Sergei Kolobov <sergei@kolobov.com>
#
# $FreeBSD$
#

PORTNAME=	gnutls
PORTVERSION=	0.5.11
CATEGORIES=	security net
MASTER_SITES=	ftp://ftp.gnutls.org/pub/gnutls/ \
	ftp://ftp.gnupg.org/pub/gcrypt/alpha/gnutls/ \
	http://www.mirrors.wiretapped.net/security/network-security/gnutls/ \
	ftp://ftp.mirrors.wiretapped.net/security/network-security/gnutls/ \

MAINTAINER=	sergei@kolobov.com

LIB_DEPENDS=	gcrypt:${PORTSDIR}/security/libgcrypt \
		tasn1:${PORTSDIR}/security/libtasn1

USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_TARGET=
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -lgnugetopt"

DOCS=		AUTHORS NEWS README THANKS

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/doc/tex/*.ps ${DOCSDIR}
.endif

.include <bsd.port.mk>
