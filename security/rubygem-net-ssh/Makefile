# New ports collection makefile for:	rubygem-net-ssh
# Date created:				14 January 2006
# Whom:					Roderick van Domburg <r.s.a.vandomburg@student.utwente.nl>
#
# $FreeBSD$
#

PORTNAME=	net-ssh
PORTVERSION=	1.1.2
CATEGORIES=	security rubygems
MASTER_SITES=	${MASTER_SITE_RUBYFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	r.s.a.vandomburg@nedforce.nl
COMMENT=	Non-interactive SSH processing

BUILD_DEPENDS=	${LOCALBASE}/${SPEC_DIR}/needle-1.3.0.gemspec:${PORTSDIR}/devel/rubygem-needle

OPTIONS=	PROMPT_PASSPHRASES "Prompt for passphrases on keys" On
OPTIONSFILE?=	${PORT_DBDIR}/rubygem-${PORTNAME}/options

# to get RUBY_SITEARCHLIBDIR
USE_RUBY=	yes
USE_RUBYGEMS=	yes

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_PROMPT_PASSPHRASES)
RUN_DEPENDS+=	${RUBY_SITEARCHLIBDIR}/termios.so:${PORTSDIR}/comms/ruby-termios
.endif

.include <bsd.port.post.mk>
