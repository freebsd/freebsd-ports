# New ports collection makefile for:	p5-App-gist
# Date created:				2012-01-04
# Whom:					Denny Lin <dennylin93@hs.ntnu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	App-gist
PORTVERSION=	0.05
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	dennylin93@hs.ntnu.edu.tw
COMMENT=	GitHub Gist creator

RUN_DEPENDS=	p5-WWW-GitHub-Gist>=0.13:${PORTSDIR}/www/p5-WWW-GitHub-Gist

PERL_CONFIGURE=	yes

CONFLICTS=	gist-[0-9]*

MAN1=		gist.1
MAN3=		App::gist.3

.include <bsd.port.mk>
