# Ports collection Makefile for:		p5-AxKit-XSP-PerForm
# Date created:					8 Jan 2002
# Whom:						dom@happygiraffe.net
#
# $FreeBSD$
#

PORTNAME=	AxKit-XSP-PerForm
PORTVERSION=	1.83
CATEGORIES=	www
MASTER_SITES=	http://www.cpan.org/authors/id/M/MS/MSERGEANT/
PKGNAMEPREFIX=	p5-

MAINTAINER=	adam@migus.org
COMMENT=	XSP Taglib for making complex forms easy

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/AxKit.pm:${PORTSDIR}/www/p5-AxKit \
		${SITE_PERL}/AxKit/XSP/WebUtils.pm:${PORTSDIR}/www/p5-AxKit-XSP-WebUtils
RUN_DEPENDS=	${BUILD_DEPENDS}

MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		AxKit::XSP::PerForm.3

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
