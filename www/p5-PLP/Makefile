# New ports collection makefile for:	PLP
# Date created:				Sun May 23 13:27:20 EDT 2004
# Whom:					Christopher Nehren <apeiron@comcast.net>
#
# $FreeBSD$
#

PORTNAME=	PLP
PORTVERSION=	3.18
CATEGORIES=	www perl5
MASTER_SITES=	http://plp.juerd.nl/files/
PKGNAMEPREFIX=	p5-

MAINTAINER=	apeiron@comcast.net
COMMENT=	A simple Perl embedder superficially resembling PHP

PERL_CONFIGURE=	yes

MAN3=		PLP.3 PLP::FAQ.3 PLP::Fields.3 PLP::Functions.3 PLP::HowTo.3 \
		PLP::Tie::Delay.3 PLP::Tie::Headers.3 PLP::Tie::Print.3

.if defined(WITH_MOD_PERL)
.if ${WITH_MOD_PERL} == 1
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/mod_perl.pm:${PORTSDIR}/www/mod_perl
.elif ${WITH_MOD_PERL} == 2
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Apache2/mod_perl.pm:${PORTSDIR}/www/mod_perl2
EXTRA_PATCHES=	${PATCHDIR}/extra-patch-mod_perl2.pm
.else
IGNORE=	WITH_MOD_PERL must be either '1' or '2', or undefined
.endif
.endif

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=	"Perl 5.6 or newer required. Install lang/perl5.[6,8] and try again"
.endif

pre-fetch:
	@${ECHO_CMD}
.if defined(WITH_MOD_PERL)
.if ${WITH_MOD_PERL} == 1
	@${ECHO_CMD} "Enabling mod_perl 1.x support."
.elif ${WITH_MOD_PERL} == 2
	@${ECHO_CMD} "Be aware that the patch to make PLP function with mod_perl 2 is"
	@${ECHO_CMD} "both unofficial and unsupported. It requires mod_perl 2's mod_perl 1"
	@${ECHO_CMD} "compatibility interface. In using mod_perl 2 you are assumed to know"
	@${ECHO_CMD} "what you are doing."
.endif
.else
	@${ECHO_CMD} "This port supports either mod_perl 1 or mod_perl 2 (with an"
	@${ECHO_CMD} "experimental patch and mod_perl 2's compat interface)."
	@${ECHO_CMD} "mod_perl is not required for PLP to function, but you"
	@${ECHO_CMD} "can expect a 50-200% speed increase with mod_perl support."
	@${ECHO_CMD}
	@${ECHO_CMD} "  WITH_MOD_PERL=1  Enables mod_perl 1.x support"
	@${ECHO_CMD} "  WITH_MOD_PERL=2 Enables unofficial, experimental mod_perl 2.x support"
.endif
	@${ECHO_CMD}
.include <bsd.port.post.mk>
