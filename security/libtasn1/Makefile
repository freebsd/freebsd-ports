# New ports collection makefile for:	libtasn1
# Date created:		15 Nov 2002
# Whom:			Sergei Kolobov <sergei@kolobov.com>
#
# $FreeBSD$
#

PORTNAME=	libtasn1
PORTVERSION=	0.2.10
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GNUPG} \
	http://www.mirrors.wiretapped.net/security/network-security/gnutls/libtasn1/ \
	ftp://ftp.mirrors.wiretapped.net/security/network-security/gnutls/libtasn1/ \
	ftp://ftp.gnutls.org/pub/gnutls/libtasn1/
MASTER_SITE_SUBDIR=	alpha/gnutls/libtasn1

MAINTAINER=	sergei@FreeBSD.org
COMMENT=	ASN.1 structure parser library

USE_LIBTOOL_VER=15
INSTALLS_SHLIB=	yes
USE_GETOPT_LONG=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

DOCS=		AUTHORS NEWS README THANKS doc/asn1.ps doc/asn1.tex doc/fdl.tex

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
