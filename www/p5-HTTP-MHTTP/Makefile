# New ports collection makefile for:	HTTP-MHTTP
# Date created:	   22 January 2004
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	HTTP-MHTTP
PORTVERSION=	0.15
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	HTTP
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Low level access to the HTTP protocol

PERL_CONFIGURE=	yes
USE_OPENSSL=	yes
CONFIGURE_ENV=	GOTSSL=yes
CONFIGURE_ARGS=	--default

MAN3=		HTTP::MHTTP.3

post-patch:
	@${PERL} -pi -e 's!(?<=POSSIBLE_SSL_DIRS = qw\().*(?=\);)!${OPENSSLBASE}!;' \
		${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
