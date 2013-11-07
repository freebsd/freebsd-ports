# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	HTTP-MHTTP
PORTVERSION=	0.15
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Low level access to the HTTP protocol

USES=		perl5
USE_PERL5=	configure patch
USE_OPENSSL=	yes
CONFIGURE_ENV=	GOTSSL=yes
CONFIGURE_ARGS=	--default

post-patch:
	@${PERL} -pi -e 's!(?<=POSSIBLE_SSL_DIRS = qw\().*(?=\);)!${OPENSSLBASE}!;' \
		${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
