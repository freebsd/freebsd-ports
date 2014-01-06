# Created by: Dima Dorfman <dima@unixfreak.org>
# $FreeBSD$

PORTNAME=	db
PORTVERSION=	20140106
CATEGORIES=	print
MASTER_SITES=	http://www.openprinting.org/download/foomatic/ \
		ftp://ftp.wart.ru/pub/FreeBSD/ports/distfiles/foomatic/
PKGNAMEPREFIX=	foomatic-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${FOOMATICVER}-${PORTVERSION}
DIST_SUBDIR=	foomatic

MAINTAINER=	bsam@FreeBSD.org
COMMENT=	Database for integrating printer drivers with common spoolers

LIB_DEPENDS=	libxml2.so:${PORTSDIR}/textproc/libxml2 \
		libcurl.so:${PORTSDIR}/ftp/curl

USES=		gmake
USE_AUTOTOOLS=	automake:env autoconf
GNU_CONFIGURE=	yes

FOOMATICVER=	4.0
WRKSRC=	${WRKDIR}/${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}
NO_ARCH=	yes

.include <bsd.port.mk>
