# Created by: Tilman Linneweh <arved@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libksba
PORTVERSION=	1.4.0
CATEGORIES=	security
MASTER_SITES=	GNUPG/${PORTNAME}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Library to make X.509 certificates

LICENSE=	GPLv2 GPLv3 LGPL3
LICENSE_COMB=	dual
LICENSE_FILE_GPLv2=	${WRKSRC}/COPYING.GPLv2
LICENSE_FILE_GPLv3=	${WRKSRC}/COPYING.GPLv3
LICENSE_FILE_LGPL3=	${WRKSRC}/COPYING.LGPLv3

LIB_DEPENDS=	libgpg-error.so:security/libgpg-error

USES=		libtool perl5 tar:bzip2
USE_PERL5=	build

CONFIGURE_ARGS=	--enable-static
INSTALL_TARGET=	install-strip
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

INFO=		ksba

.include <bsd.port.mk>
