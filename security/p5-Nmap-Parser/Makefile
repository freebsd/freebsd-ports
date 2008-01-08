# New ports collection makefile for: 	p5-Nmap-Parser
# Date created:				June 3 2006
# Whom:					Joshua D. Abraham <jabra@ccs.neu.edu>
#
# $FreeBSD$
#

PORTNAME=	Nmap-Parser
PORTVERSION=	1.12
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/A/AP/APERSAUD
PKGNAMEPREFIX=	p5-

MAINTAINER=	jabra@ccs.neu.edu
COMMENT=	Parse nmap scan data with perl

BUILD_DEPENDS=	${SITE_PERL}/XML/Twig.pm:${PORTSDIR}/textproc/p5-XML-Twig
RUN_DEPENDS=	${BUILD_DEPENDS} \
		nmap:${PORTSDIR}/security/nmap

PERL_CONFIGURE=	yes

MAN3=		Nmap::Parser.3

post-configure:
	@${PERL} -pi -e 's/^(POD2MAN_EXE.*)$$/\1 --lax/;' ${WRKSRC}/Makefile

.include <bsd.port.mk>
