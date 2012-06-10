# New ports collection makefile for:	p5-WebService-Basecamp
# Date created:		2006-08-18
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	WebService-Basecamp
PORTVERSION=	0.1.4
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl interface to the Basecamp API webservice

RUN_DEPENDS=	p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-XML-Simple>=0:${PORTSDIR}/textproc/p5-XML-Simple
BUILD_DEPENDS:=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		WebService::Basecamp.3

.include <bsd.port.mk>
