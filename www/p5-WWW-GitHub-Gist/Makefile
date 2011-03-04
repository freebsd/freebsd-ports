# New ports collection makefile for:	p5-WWW-GitHub-Gist
# Date created:				2010-09-02
# Whom:					Denny Lin <dennylin93@hs.ntnu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	WWW-GitHub-Gist
PORTVERSION=	0.06
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:ALEXBIO
PKGNAMEPREFIX=	p5-

MAINTAINER=	dennylin93@hs.ntnu.edu.tw
COMMENT=	Perl interface to Gist

CONFLICTS=	gist-[0-9]*

RUN_DEPENDS=	p5-HTTP-Tiny>=0:${PORTSDIR}/www/p5-HTTP-Tiny \
		p5-JSON>=0:${PORTSDIR}/converters/p5-JSON

PERL_CONFIGURE=	yes

MAN1=		gist.1
MAN3=		WWW::GitHub::Gist.3

.include <bsd.port.mk>
