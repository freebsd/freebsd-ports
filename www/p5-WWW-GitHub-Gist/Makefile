# New ports collection makefile for:	p5-WWW-GitHub-Gist
# Date created:				2010-09-02
# Whom:					Denny Lin <dennylin93@hs.ntnu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	WWW-GitHub-Gist
PORTVERSION=	0.13
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:ALEXBIO
PKGNAMEPREFIX=	p5-

MAINTAINER=	dennylin93@hs.ntnu.edu.tw
COMMENT=	Perl interface to Gist

RUN_DEPENDS=	p5-HTTP-Tiny>=0:${PORTSDIR}/www/p5-HTTP-Tiny \
		p5-JSON>=0:${PORTSDIR}/converters/p5-JSON \
		p5-Any-Moose>=0:${PORTSDIR}/devel/p5-Any-Moose

PERL_CONFIGURE=	yes

MAN3=		WWW::GitHub::Gist.3 \
		WWW::GitHub::Gist::v2.3 \
		WWW::GitHub::Gist::v3.3

.include <bsd.port.mk>
