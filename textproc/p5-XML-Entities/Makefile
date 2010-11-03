# New ports collection makefile for:	p5-XML-Entities
# Date created:				2010-10-1
# Whom:					Tom Judge <tom@tomjudge.com>
#
# $FreeBSD$

PORTNAME=	XML-Entities
PORTVERSION=	1.0000
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tom@tomjudge.com
COMMENT=	Generic classes for simplistic and perlish handling of XML data

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/HTML/Parser.pm:${PORTSDIR}/www/p5-HTML-Parser \
		${SITE_PERL}/LWP/Simple.pm:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

MAN3=		XML::Entities.3pm XML::Entities::Data.3pm download-entities.pl.3pm
MAN1=		download-entities.pl.1

.include <bsd.port.mk>
