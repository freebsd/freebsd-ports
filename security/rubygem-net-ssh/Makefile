PORTNAME=	net-ssh
PORTVERSION=	8.1.2
PORTEPOCH=	2
CATEGORIES=	security rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Non-interactive SSH processing
WWW=		https://github.com/net-ssh/net-ssh

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-logger>=0:devel/rubygem-logger \
		rubygem-openssl>=3.2.0:security/rubygem-openssl

USES=		gem

NO_ARCH=	yes

OPTIONS_DEFINE=	PROMPT_PASSPHRASES
OPTIONS_DEFAULT=PROMPT_PASSPHRASES
PROMPT_PASSPHRASES_DESC=	Prompt for passphrases on keys

PROMPT_PASSPHRASES_RUN_DEPENDS=	rubygem-ruby-termios>=0:comms/rubygem-ruby-termios

.include <bsd.port.mk>
