# New ports collection makefile for:	Lingua::EN::MatchNames
# Date created:				30 Dec 2001
# Whom:					Seamus Venasse <svenasse@polaris.ca>
#
# $FreeBSD$
#

PORTNAME=	Lingua-EN-MatchNames
PORTVERSION=	1.12
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Lingua
PKGNAMEPREFIX=	p5-

MAINTAINER=	svenasse@polaris.ca
COMMENT=	Smart matching for human names

BUILD_DEPENDS=	${SITE_PERL}/Lingua/EN/NameParse.pm:${PORTSDIR}/textproc/p5-Lingua-EN-NameParse \
		${SITE_PERL}/Lingua/EN/Nickname.pm:${PORTSDIR}/textproc/p5-Lingua-EN-Nickname \
		${SITE_PERL}/${PERL_ARCH}/String/Approx.pm:${PORTSDIR}/devel/p5-String-Approx \
		${SITE_PERL}/${PERL_ARCH}/Text/Metaphone.pm:${PORTSDIR}/textproc/p5-Text-Metaphone
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Lingua::EN::MatchNames.3

.include <bsd.port.mk>
