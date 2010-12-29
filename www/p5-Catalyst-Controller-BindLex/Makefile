# Ports collection makefile for:	p5-Catalyst-Controller-BindLex
# Date created:				17.Oct.2006
# Whom:					Fernan Aguero  <fernan@iib.unsam.edu.ar>
#
# $FreeBSD$
#

PORTNAME=	Catalyst-Controller-BindLex
PORTVERSION=	0.03
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../by-authors/id/N/NU/NUFFIN
PKGNAMEPREFIX=	p5-

MAINTAINER=	fernan@iib.unsam.edu.ar
COMMENT=	Stash your lexical goodness

BUILD_DEPENDS=	${SITE_PERL}/Catalyst.pm:${PORTSDIR}/www/p5-Catalyst-Runtime \
		${SITE_PERL}/${PERL_ARCH}/Array/RefElem.pm:${PORTSDIR}/misc/p5-Array-RefElem \
		${SITE_PERL}/${PERL_ARCH}/Devel/Caller.pm:${PORTSDIR}/devel/p5-Devel-Caller \
		${SITE_PERL}/${PERL_ARCH}/Devel/LexAlias.pm:${PORTSDIR}/devel/p5-Devel-LexAlias \
		${SITE_PERL}/${PERL_ARCH}/PadWalker.pm:${PORTSDIR}/devel/p5-PadWalker \
		${SITE_PERL}/Test/use/ok.pm:${PORTSDIR}/devel/p5-Test-use-ok
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_MODBUILD=	5.8.1+

MAN3=	Catalyst::Controller::BindLex.3

.include <bsd.port.mk>
