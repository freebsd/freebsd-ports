# New ports collection makefile for:	libtasn1
# Date created:		15 Nov 2002
# Whom:			Sergei Kolobov <sergei@kolobov.com>
#
# $FreeBSD$
#

PORTNAME=	libtasn1
PORTVERSION=	0.2.5
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GNUPG} \
	http://www.mirrors.wiretapped.net/security/network-security/gnutls/libtasn1/ \
	ftp://ftp.mirrors.wiretapped.net/security/network-security/gnutls/libtasn1/ \
	ftp://ftp.gnutls.org/pub/gnutls/libtasn1/
MASTER_SITE_SUBDIR=	alpha/gnutls/libtasn1

MAINTAINER=	sergei@FreeBSD.org
COMMENT=	ASN.1 structure parser library

USE_REINPLACE=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
USE_GETOPT_LONG=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

DOCS=		AUTHORS NEWS README THANKS doc/asn1.ps doc/asn1.tex doc/fdl.tex

post-patch:
.for file in asn1Coding.c asn1Decoding.c asn1Parser.c
	${REINPLACE_CMD} -e 's/<malloc.h>/<stdlib.h>/' ${WRKSRC}/src/${file}
.endfor

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
