# New ports collection makefile for:	libtasn1
# Date created:		15 Nov 2002
# Whom:			Sergei Kolobov <sergei@kolobov.com>
#
# $FreeBSD$
#

PORTNAME=	libtasn1
PORTVERSION=	0.1.2
CATEGORIES=	security
MASTER_SITES=	http://gd.tuwien.ac.at/privacy/gnupg/alpha/gnutls/libtasn1/ \
	http://www.mirrors.wiretapped.net/security/network-security/gnutls/libtasn1/ \
	ftp://ftp.gnupg.org/pub/gcrypt/alpha/gnutls/libtasn1/ \
	ftp://ftp.mirrors.wiretapped.net/security/network-security/gnutls/libtasn1/ \
	ftp://ftp.gnutls.org/pub/gnutls/libtasn1/

MAINTAINER=	sergei@kolobov.com

LIB_DEPENDS=	gnugetopt.1:${PORTSDIR}/devel/libgnugetopt

USE_REINPLACE=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lgnugetopt
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

DOCS=		AUTHORS NEWS README THANKS
DOCS2=		asn1.ps asn1.tex fdl.tex

post-patch:
.for file in asn1Coding.c asn1Decoding.c asn1Parser.c
	${REINPLACE_CMD} -e 's/<malloc.h>/<stdlib.h>/' ${WRKSRC}/src/${file}
.endfor

post-install:
	${RM} -f ${PREFIX}/lib/libtasn1.la
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.for file in ${DOCS2}
	${INSTALL_DATA} ${WRKSRC}/doc/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
