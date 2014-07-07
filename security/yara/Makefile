# $FreeBSD$

PORTNAME=	yara
PORTVERSION=	2.1.0
PORTREVISION=	1
CATEGORIES=	security

MAINTAINER=	wxs@FreeBSD.org
COMMENT=	Malware identification and classification tool

USE_GITHUB=	yes
GH_ACCOUNT=	plusvic
GH_TAGNAME=	v2.1.0
GH_COMMIT=	6530e73

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USES=		libtool
USE_AUTOTOOLS=	libtoolize aclocal autoconf autoheader automake
AUTOMAKE_ARGS=	-a -c -f
USE_LDCONFIG=	yes
MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.mk>
