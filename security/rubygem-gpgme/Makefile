# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gpgme
PORTVERSION=	2.0.19
CATEGORIES=	security rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ruby interface to GnuPG Made Easy (GPGME)

LICENSE=	LGPL21+

BUILD_DEPENDS=	gpgme-config:security/gpgme
LIB_DEPENDS=	libassuan.so:security/libassuan \
		libgpg-error.so:security/libgpg-error
RUN_DEPENDS=	gpgme-config:security/gpgme

USES=		gem shebangfix
USE_RUBY=	yes

CONFIGURE_ARGS=	--use-system-libraries

SHEBANG_FILES=	test/pinentry

post-patch:
	@${REINPLACE_CMD} -e '/mini_portile2/d' ${WRKSRC}/gpgme.gemspec ${WRKSRC}/ext/gpgme/extconf.rb

.include <bsd.port.mk>
