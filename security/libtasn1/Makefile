# New ports collection makefile for:	libtasn1
# Date created:		15 Nov 2002
# Whom:			Sergei Kolobov <sergei@kolobov.com>
#
# $FreeBSD$
#

PORTNAME=	libtasn1
PORTVERSION=	0.2.1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GNUPG} \
	http://www.mirrors.wiretapped.net/security/network-security/gnutls/libtasn1/ \
	ftp://ftp.mirrors.wiretapped.net/security/network-security/gnutls/libtasn1/ \
	ftp://ftp.gnutls.org/pub/gnutls/libtasn1/
MASTER_SITE_SUBDIR=	alpha/gnutls/libtasn1

MAINTAINER=	sergei@kolobov.com
COMMENT=	ASN.1 structure parser library

.if !exists(/usr/include/getopt.h)
LIB_DEPENDS=	gnugetopt.1:${PORTSDIR}/devel/libgnugetopt
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lgnugetopt
.endif

USE_REINPLACE=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

DOCS=		AUTHORS NEWS README THANKS doc/asn1.ps doc/asn1.tex doc/fdl.tex

post-patch:
.for file in asn1Coding.c asn1Decoding.c asn1Parser.c
	${REINPLACE_CMD} -e 's/<malloc.h>/<stdlib.h>/' ${WRKSRC}/src/${file}
.endfor

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
.for file in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
