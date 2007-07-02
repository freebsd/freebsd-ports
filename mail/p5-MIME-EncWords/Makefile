# New ports collection makefile for:	mail/p5-MIME-EncWords
# Date created:				05 June 2007
# Whom:					Olivier Girard <Olivier.Girard@univ-angers.fr>
#
# $FreeBSD$
#

PORTNAME=	MIME-EncWords
PORTVERSION=	0.040
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	MIME
PKGNAMEPREFIX=	p5-

MAINTAINER=	Olivier.Girard@univ-angers.fr
COMMENT=	MIME::EncWords - deal with RFC-1522 encoded words (improved)

BUILD_DEPENDS=	${SITE_PERL}/MIME/Charset.pm:${PORTSDIR}/mail/p5-MIME-Charset \
		${SITE_PERL}/MIME/Body.pm:${PORTSDIR}/mail/p5-MIME-Tools
RUN_DEPENDS=	${SITE_PERL}/MIME/Charset.pm:${PORTSDIR}/mail/p5-MIME-Charset \
		${SITE_PERL}/MIME/Body.pm:${PORTSDIR}/mail/p5-MIME-Tools

PERL_CONFIGURE=	yes

MAN3=		MIME::EncWords.3

.include <bsd.port.mk>
