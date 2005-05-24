# New ports collection makefile for:	textproc/p5-YAML
# Date created:				01 May 2003
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	YAML
PORTVERSION=	0.39
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	YAML
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	"YAML implementation in Perl"

PERL_CONFIGURE=	yes
CONFIGURE_ARGS+=	</dev/null

MAN1=		ysh.1
MAN3=		YAML.3 YAML::Node.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
post-install:
	@${ECHO} ""
	@${ECHO} "You are using an old version of Perl."
	@${ECHO} ""
	@${ECHO} "YAML.pm module is known to be buggy with your"
	@${ECHO} "version of Perl.  It should mostly work, but"
	@${ECHO} "it will not be able to dump Perl code correctly."
	@${ECHO} ""
	@${ECHO} "Perhaps you should consider an upgrade."
	@${ECHO} ""
.endif

.include <bsd.port.post.mk>
