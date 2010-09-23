# New ports collection makefile for:	p5-WWW-GitHub-Gist
# Date created:				2010-09-02
# Whom:					Denny Lin <dennylin93@hs.ntnu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	WWW-GitHub-Gist
PORTVERSION=	0.05
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	dennylin93@hs.ntnu.edu.tw
COMMENT=	Perl interface to Gist

BUILD_DEPENDS=	${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple \
		${SITE_PERL}/LWP/UserAgent.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/JSON.pm:${PORTSDIR}/converters/p5-JSON
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=		gist.pl.1
MAN3=		WWW::GitHub::Gist.3

.include <bsd.port.mk>
