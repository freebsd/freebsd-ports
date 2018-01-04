# $FreeBSD$

PORTNAME=	bcrypt_pbkdf
PORTVERSION=	1.0.0
CATEGORIES=	security rubygems
MASTER_SITES=	RG

MAINTAINER=	idefix@fechner.net
COMMENT=	This gem implements bcrypt_pdkfd

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	rubygem-minitest>=5:devel/rubygem-minitest \
		rubygem-rake-compiler>=0.9.7:devel/rubygem-rake-compiler \
		rubygem-rake-compiler-dock>=0.5.3:devel/rubygem-rake-compiler-dock \
		rubygem-rbnacl>=3.3:security/rubygem-rbnacl \
		rubygem-rbnacl-libsodium>=1.0.8:security/rubygem-rbnacl-libsodium \
		rubygem-rdoc>=3.12:devel/rubygem-rdoc
LIB_DEPENDS=	libunwind.so:devel/libunwind \
		libgmp.so:math/gmp

USES=		gem
USE_RUBY=	yes

.include <bsd.port.mk>
