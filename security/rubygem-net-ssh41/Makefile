# $FreeBSD$

PORTNAME=	net-ssh
PORTVERSION=	4.1.0
CATEGORIES=	security rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	41

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Non-interactive SSH processing

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

DEPRECATED=	Obsoleted by update of www/gitlab. Please use security/rubygem-net-ssh instead.
EXPIRATION_DATE=	2018-06-30

OPTIONS_DEFINE=	PROMPT_PASSPHRASES
OPTIONS_DEFAULT=PROMPT_PASSPHRASES
PROMPT_PASSPHRASES_DESC=	Prompt for passphrases on keys

PORTSCOUT=	limit:^4\.1

NO_ARCH=	yes
USES=		gem shebangfix
USE_RUBY=	yes
SHEBANG_FILES=	support/ssh_tunnel_bug.rb

PROMPT_PASSPHRASES_RUN_DEPENDS=	rubygem-ruby-termios>=0:comms/rubygem-ruby-termios

.include <bsd.port.mk>
