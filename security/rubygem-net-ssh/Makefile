# Created by: Roderick van Domburg <r.s.a.vandomburg@student.utwente.nl>

PORTNAME=	net-ssh
PORTVERSION=	7.0.1
PORTEPOCH=	2
CATEGORIES=	security rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Non-interactive SSH processing

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		gem shebangfix
USE_RUBY=	yes

NO_ARCH=	yes

SHEBANG_FILES=	support/ssh_tunnel_bug.rb

OPTIONS_DEFINE=	PROMPT_PASSPHRASES
OPTIONS_DEFAULT=PROMPT_PASSPHRASES
PROMPT_PASSPHRASES_DESC=	Prompt for passphrases on keys

PROMPT_PASSPHRASES_RUN_DEPENDS=	rubygem-ruby-termios>=0:comms/rubygem-ruby-termios

.include <bsd.port.mk>
