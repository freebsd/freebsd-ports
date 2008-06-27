# New ports collection makefile for:	rubygem-net-ssh
# Date created:				14 January 2006
# Whom:					Roderick van Domburg <r.s.a.vandomburg@student.utwente.nl>
#
# $FreeBSD$
#

PORTNAME=	net-ssh
PORTVERSION=	2.0.2
CATEGORIES=	security rubygems
MASTER_SITES=	RF

MAINTAINER=	r.s.a.vandomburg@nedforce.nl
COMMENT=	Non-interactive SSH processing

OPTIONS=	PROMPT_PASSPHRASES "Prompt for passphrases on keys" On

# to get RUBY_SITEARCHLIBDIR
USE_RUBY=	yes
USE_RUBYGEMS=	yes

.if !defined(WITHOUT_PROMPT_PASSPHRASES)
RUN_DEPENDS+=	${RUBY_SITEARCHLIBDIR}/termios.so:${PORTSDIR}/comms/ruby-termios
.endif

.include <bsd.port.mk>
