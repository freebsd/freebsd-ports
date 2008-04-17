# New ports collection makefile for:	XML::XUpdate::LibXML
# Date created:		15 July 2002
# Whom:			Lev Serebryakov <lev@serebryakov.spb.ru>
#
# $FreeBSD$
#

PORTNAME=	XML-XUpdate-LibXML
PORTVERSION=	0.6.0
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lev@FreeBSD.org
COMMENT=	Simple implementation of XUpdate format based on and XML::LibXML

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/XML/LibXML.pm:${PORTSDIR}/textproc/p5-XML-LibXML \
		${SITE_PERL}/XML/LibXML/Iterator.pm:${PORTSDIR}/textproc/p5-XML-LibXML-Iterator
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=		xupdate.1
MAN3=		XML::Normalize::LibXML.3 XML::XUpdate::LibXML.3

.include <bsd.port.mk>
