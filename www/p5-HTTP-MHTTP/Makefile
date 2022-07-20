PORTNAME=	HTTP-MHTTP
PORTVERSION=	0.15
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Low level access to the HTTP protocol

USES=		perl5 ssl
USE_PERL5=	configure patch
CONFIGURE_ENV=	GOTSSL=yes
CONFIGURE_ARGS=	--default

MAKE_JOBS_UNSAFE=	yes

post-patch:
	@${PERL} -pi -e 's!(?<=POSSIBLE_SSL_DIRS = qw\().*(?=\);)!${OPENSSLBASE}!;' \
		${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
