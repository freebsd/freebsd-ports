# New ports collection makefile for:	rubygem-net-ssh
# Date created:				14 January 2006
# Whom:					Roderick van Domburg <r.s.a.vandomburg@student.utwente.nl>
#
# $FreeBSD$
#

PORTNAME=	net-ssh
PORTVERSION=	1.0.6
CATEGORIES=	security ruby
MASTER_SITES=	http://rubyforge.org/frs/download.php/8149/

MAINTAINER=	r.s.a.vandomburg@student.utwente.nl
COMMENT=	Non-interactive SSH processing

BUILD_DEPENDS=	${LOCALBASE}/${SPEC_DIR}/needle-1.3.0.gemspec:${PORTSDIR}/devel/rubygem-needle

OPTIONS=	PROMPT_PASSPHRASES "Prompt for passphrases on keys" On
OPTIONSFILE=	${PORTS_DBDIR}/rubygem-${PORTNAME}/options

# to get RUBY_SITELIBDIR
USE_RUBY=	yes

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_PROMPT_PASSPHRASES)
RUN_DEPENDS+=	${RUBY_SITELIBDIR}/password.rb:${PORTSDIR}/security/ruby-password
.endif

post-install:
	@${ECHO} "You may safely ignore any 'Skipping require of dynamic string' messages."

.include "${PORTSDIR}/devel/ruby-gems/Makefile.common"
.include <bsd.port.post.mk>
