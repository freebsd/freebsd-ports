# New ports collection makefile for:	mail/p5-MIME-EncWords
# Date created:				05 June 2007
# Whom:					Olivier Girard <Olivier.Girard@univ-angers.fr>
#
# $FreeBSD$
#

PORTNAME=	MIME-EncWords
PORTVERSION=	1.011.1
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	Olivier.Girard@univ-angers.fr
COMMENT=	Deal with RFC 2047 encoded words (improved)

RUN_DEPENDS=	p5-MIME-Charset>=1.006.2:${PORTSDIR}/mail/p5-MIME-Charset

USES=		perl5
USE_PERL5=	configure

MAN3=		MIME::EncWords.3 MIME::EncWords::JA_JP.3

.include <bsd.port.mk>
