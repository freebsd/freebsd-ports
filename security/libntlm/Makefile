PORTNAME=	libntlm
PORTVERSION=	1.8
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	SAVANNAH

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Library that implement Microsoft's NTLM authentication
WWW=		https://gitlab.com/gsasl/libntlm

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cpe libtool pkgconfig

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

CPE_VENDOR=	nongnu

.include <bsd.port.mk>
