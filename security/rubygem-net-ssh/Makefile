# New ports collection makefile for:	rubygem-net-ssh
# Date created:				14 January 2006
# Whom:					Roderick van Domburg <r.s.a.vandomburg@student.utwente.nl>
#
# $FreeBSD$
#
# Remeber to check sysutils/rubygem-chef

PORTNAME=	net-ssh
PORTVERSION=	2.1.4
PORTEPOCH=	2
CATEGORIES=	security rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Non-interactive SSH processing

OPTIONS=	PROMPT_PASSPHRASES "Prompt for passphrases on keys" On
OPTIONSFILE?=	${PORT_DBDIR}/rubygem-${PORTNAME}/options

# to get RUBY_SITEARCHLIBDIR
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.if !defined(WITHOUT_PROMPT_PASSPHRASES)
RUN_DEPENDS+=	rubygem-ruby-termios>=0:${PORTSDIR}/comms/rubygem-ruby-termios
.endif

.include <bsd.port.mk>
