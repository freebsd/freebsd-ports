# New ports collection makefile for:	Mail-FilterXML
# Date created:				Wed Jan  3 14:28:38 2001
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	Mail-FilterXML
PORTVERSION=	0.3
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Mail
PKGNAMEPREFIX=	p5-

MAINTAINER=	erwin@FreeBSD.org
COMMENT=	Perl module that allows writing mail filter rules in XML

BUILD_DEPENDS=	${SITE_PERL}/Mail/Audit.pm:${PORTSDIR}/mail/p5-Mail-Audit \
		${SITE_PERL}/${PERL_ARCH}/XML/Parser.pm:${PORTSDIR}/textproc/p5-XML-Parser
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Mail::FilterXML.3

.include <bsd.port.mk>
