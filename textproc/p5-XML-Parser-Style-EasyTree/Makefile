# New ports collection makefile for:	textproc/p5-XML-Parser-Style-EasyTree
# Date created:				28 July 2009
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	XML-Parser-Style-EasyTree
PORTVERSION=	0.09
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	XML
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Parse XML to a simple tree

BUILD_DEPENDS=	p5-XML-Parser>0:${PORTSDIR}/textproc/p5-XML-Parser \
		p5-ex-lib>=0.03:${PORTSDIR}/devel/p5-ex-lib
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	XML::Parser::Style::EasyTree.3 XML::Parser::Style::ETree.3

.include <bsd.port.mk>
