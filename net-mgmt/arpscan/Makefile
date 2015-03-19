# Created by: David Yeske <dyeske@gmail.com>
# $FreeBSD$

PORTNAME=	arpscan
PORTVERSION=	0.5
PORTREVISION=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	GHL
DIST_SUBDIR=	repacked

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple arp scanner

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libdnet.so:${PORTSDIR}/net/libdnet

USE_GITHUB=	yes
GH_ACCOUNT=	jasonish
GH_TAGNAME=	${GH_COMMIT}
GH_COMMIT=	e59831a

USE_AUTOTOOLS=	aclocal autoheader automake autoconf
AUTOMAKE_ARGS=	--add-missing --copy
CONFIGURE_ARGS=--with-libdnet=${LOCALBASE}

PLIST_FILES=	bin/arpscan

.include <bsd.port.mk>
