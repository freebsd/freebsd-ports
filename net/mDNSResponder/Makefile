# ex:ts=8
# Ports collection makefile for:  mDNSResponder
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

MAINTAINER=	alfred@freebsd.org
COMMENT=	"Apple's mDNSResponder"

INSTALLS_SHLIB=	YES

USE_GMAKE=	YES
MAKE_ARGS+=	os=freebsd
BUILD_WRKSRC=	${WRKSRC}/mDNSPosix
INSTALL_WRKSRC=	${WRKSRC}/mDNSPosix

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000 || ( ${ARCH} != "i386" && ${ARCH} != "ia64" )
BROKEN=		"Does not compile on 4.x or on !i386 and !ia64"
.endif

.include <bsd.port.post.mk>
