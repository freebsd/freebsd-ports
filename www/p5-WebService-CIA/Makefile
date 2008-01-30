# New ports collection makefile for:	p5-WebService-CIA
# Date created:		2007-05-02
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	WebService-CIA
PORTVERSION=	1.4
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Information from the CIA World Factbook

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Crypt/SSLeay.pm:${PORTSDIR}/security/p5-Crypt-SSLeay \
		${SITE_PERL}/LWP/UserAgent.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/MLDBM.pm:${PORTSDIR}/databases/p5-MLDBM
BUILD_DEPENDS=	${RUN_DEPENDS}

CONFIGURE_ARGS=	</dev/null
PERL_MODBUILD=	yes

MAN3=		WebService::CIA.3 WebService::CIA::Parser.3 \
		WebService::CIA::Source.3 WebService::CIA::Source::DBM.3 \
		WebService::CIA::Source::Web.3

.include <bsd.port.mk>
