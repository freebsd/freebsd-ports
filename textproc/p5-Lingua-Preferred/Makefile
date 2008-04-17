# New ports collection makefile for:	Lingua::Preferred
# Date created:				30 Dec 2001
# Whom:					Seamus Venasse <svenasse@polaris.ca>
#
# $FreeBSD$
#

PORTNAME=		Lingua-Preferred
PORTVERSION=		0.2.4
CATEGORIES=		textproc perl5
MASTER_SITES=		CPAN
MASTER_SITE_SUBDIR=	../../authors/id/E/ED/EDAVIS
PKGNAMEPREFIX=		p5-

MAINTAINER=		perl@FreeBSD.org
COMMENT=	Perl extension to choose a language

BUILD_DEPENDS=	${SITE_PERL}/Log/TraceMessages.pm:${PORTSDIR}/devel/p5-Log-TraceMessages
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=		yes

MAN3=			Lingua::Preferred.3

.include <bsd.port.mk>
