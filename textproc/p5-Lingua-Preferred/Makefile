# New ports collection makefile for:	Lingua::Preferred
# Date created:				30 Dec 2001
# Whom:					Seamus Venasse <svenasse@polaris.ca>
#
# $FreeBSD$
#

PORTNAME=		Lingua-Preferred
PORTVERSION=		0.1.1
CATEGORIES=		textproc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Lingua
PKGNAMEPREFIX=		p5-

MAINTAINER=		svenasse@polaris.ca

RUN_DEPENDS=	${LOCALBASE}/lib/perl5/${PERL_VER}/Log/TraceMessage.pm:${PORTSDIR}/devel/p5-Log-TraceMessages

PERL_CONFIGURE=		yes

MAN3=			Lingua::Preferred.3
MANPREFIX=		${PREFIX}/lib/perl5/${PERL_VERSION}

.include <bsd.port.mk>
