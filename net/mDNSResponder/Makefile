# ex:ts=8
# Ports collection makefile for:  mdnsresponder
# Date created:			  Tues Mar 2, 2004
# Whom:				  Alfred Perlstein <alfred@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	mDNSResponder
PORTVERSION=	62
#PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://darwinsource.opendarwin.org/tarballs/apsl/

DISTNAME=	${PORTNAME}-${PORTVERSION}
#EXTRACT_SUFX=	.tgz

#PATCH_SITES=	ftp://sith.mimuw.edu.pl/pub/users/baggins/IPv6/
#PATCHFILES=	nc-v6-20000918.patch.gz
#PATCH_DIST_STRIP=	-p1

USE_GMAKE=	YES
MAKE_ARGS+=	os=freebsd
BUILD_WRKSRC=	${WRKSRC}/mDNSPosix
INSTALL_WRKSRC=	${WRKSRC}/mDNSPosix

MAINTAINER=	alfred@freebsd.org
COMMENT=	"Apple's mDNSResponder"

.include <bsd.port.mk>
