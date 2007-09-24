# New ports collection makefile for:	textproc/p5-XML-SAX-Expat-Incremental
# Date created:				22 December 2005
# Whom:					Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	XML-SAX-Expat-Incremental
PORTVERSION=	0.05
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	XML::SAX::Expat subclass for non-blocking (incremental)

RUN_DEPENDS=	p5-XML-Parser>0:${PORTSDIR}/textproc/p5-XML-Parser \
		p5-XML-SAX-Expat>0:${PORTSDIR}/textproc/p5-XML-SAX-Expat
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	XML::SAX::Expat::Incremental.3

.include <bsd.port.mk>
