# New ports collection makefile for:	XML-SAXDriver-Sablotron
# Date created:	   30 May 2002
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	XML-SAXDriver-Sablotron
PORTVERSION=	0.30
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Perl SAX driver for the Sablotron XSLT

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/XML/Sablotron.pm:${PORTSDIR}/textproc/p5-XML-Sablotron \
		${SITE_PERL}/XML/SAX/Base.pm:${PORTSDIR}/textproc/p5-XML-SAX
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		XML::SAXDriver::Sablotron.3

pre-patch:
	@${PERL} -pi -e 's!^use warnings;!!;' ${WRKSRC}/Sablotron.pm

.include <bsd.port.mk>
