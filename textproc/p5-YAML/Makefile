# New ports collection makefile for:	textproc/p5-YAML
# Date created:				01 May 2003
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	YAML
PORTVERSION=	0.57
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	YAML
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	YAML implementation in Perl

BUILD_DEPENDS=	\
	p5-Test-Base>=0.47:${PORTSDIR}/devel/p5-Test-Base
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes
CONFIGURE_ARGS+=	</dev/null

MAN1=	ysh.1
MAN3=	\
	Test::YAML.3 \
	YAML.3 \
	YAML::Base.3 \
	YAML::Dumper.3 \
	YAML::Dumper::Base.3 \
	YAML::Error.3 \
	YAML::Loader.3 \
	YAML::Loader::Base.3 \
	YAML::Marshall.3 \
	YAML::Node.3 \
	YAML::Tag.3 \
	YAML::Types.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
IGNORE=		requires perl 5.6.1 or later. Install lang/perl5.8 and try again
.endif

.if ${PERL_LEVEL} < 500803
post-install:
	@${ECHO_MSG} ""
	@${ECHO_MSG} "===> You are using an old version of Perl."
	@${ECHO_MSG} ""
	@${ECHO_MSG} "===> YAML.pm module is known to be buggy with your"
	@${ECHO_MSG} "===> version of Perl.  It should mostly work, but"
	@${ECHO_MSG} "===> it will not be able to dump Perl code correctly."
	@${ECHO_MSG} ""
	@${ECHO_MSG} "===> Perhaps you should consider an upgrade."
	@${ECHO_MSG} ""
.endif

.include <bsd.port.post.mk>
