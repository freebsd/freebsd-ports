PORTNAME=	gpgmepp
PORTVERSION=	2.0.0
CATEGORIES=	security
MASTER_SITES=	GNUPG

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	GnuPG Made Easy (GPGME) C++ bindings
WWW=		https://gnupg.org/software/gpgme/index.html

LICENSE=	LGPL20+
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

LIB_DEPENDS=	libgpg-error.so:security/libgpg-error \
		libgpgme.so:security/gpgme

USES=		cmake compiler:c++17-lang pkgconfig tar:xz

.include <bsd.port.mk>
