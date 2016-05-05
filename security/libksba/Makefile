# Created by: Tilman Linneweh <arved@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libksba
PORTVERSION=	1.3.4
CATEGORIES=	security
MASTER_SITES=	GNUPG/${PORTNAME}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	KSBA is an X.509 Library

LICENSE=	GPLv2 GPLv3 LGPL3
LICENSE_COMB=	dual
LICENSE_FILE_GPLv2=	${WRKSRC}/COPYING.GPLv2
LICENSE_FILE_GPLv3=	${WRKSRC}/COPYING.GPLv3
LICENSE_FILE_LGPL3=	${WRKSRC}/COPYING.LGPLv3

LIB_DEPENDS=	libgpg-error.so:security/libgpg-error

CONFIGURE_ARGS=	--enable-static
INSTALL_TARGET=	install-strip
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_PERL5=	build
USES=		libtool perl5 tar:bzip2

INFO=		ksba

.include <bsd.port.mk>
