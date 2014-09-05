# Created by: Roderick van Domburg <r.s.a.vandomburg@student.utwente.nl>
# $FreeBSD$

PORTNAME=	net-ssh
PORTVERSION=	2.9.1
PORTEPOCH=	2
CATEGORIES=	security rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Non-interactive SSH processing

LICENSE=	MIT

OPTIONS_DEFINE=	PROMPT_PASSPHRASES
OPTIONS_DEFAULT=PROMPT_PASSPHRASES
OPTIONSFILE?=	${PORT_DBDIR}/rubygem-${PORTNAME}/options
PROMPT_PASSPHRASES_DESC=	Prompt for passphrases on keys

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PROMPT_PASSPHRASES_RUN_DEPENDS=	rubygem-ruby-termios>=0:${PORTSDIR}/comms/rubygem-ruby-termios

.include <bsd.port.mk>
