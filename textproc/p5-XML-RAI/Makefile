# New ports collection makefile for:	p5-XML-RAI
# Date created:				2004-05-22
# Whom:					arved
#
# $FreeBSD$

PORTNAME=	XML-RAI
PORTVERSION=	0.41
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	XML
PKGNAMEPREFIX=	p5-

MAINTAINER=	arved@FreeBSD.org
COMMENT=	RSS Abstraction Interface

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/XML/RSS/Parser.pm:${PORTSDIR}/textproc/p5-XML-RSS-Parser

PERL_CONFIGURE=	yes

MAN3=	XML::RAI::Object.3 XML::RAI::Item.3 XML::RAI.3 XML::RAI::Image.3 \
	XML::RAI::Channel.3
.include <bsd.port.mk>
