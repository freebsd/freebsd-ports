# New ports collection makefile for: 	p5-Nmap-Parser
# Date created:				June 3 2006
# Whom:					Joshua D. Abraham <jabra@ccs.neu.edu>
#
# $FreeBSD$
#

PORTNAME=	Nmap-Parser
PORTVERSION=	1.19
PORTREVISION=	1
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	jadawin@FreeBSD.org
COMMENT=	Parse nmap scan data with perl

BUILD_DEPENDS=	p5-XML-Twig>=3.16:${PORTSDIR}/textproc/p5-XML-Twig \
		p5-Storable>=2:${PORTSDIR}/devel/p5-Storable
RUN_DEPENDS=	${BUILD_DEPENDS} \
		nmap:${PORTSDIR}/security/nmap

PERL_CONFIGURE=	yes

MAN3=		Nmap::Parser.3

post-configure:
	@${PERL} -pi -e 's/^(POD2MAN_EXE.*)$$/\1 --lax/;' ${WRKSRC}/Makefile

.include <bsd.port.mk>
