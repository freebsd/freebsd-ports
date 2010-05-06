# New ports collection makefile for:	p5-XML-Reader
# Date created:				20 Oct, 2009
# Whom:					Wen Heping <wen@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	XML-Reader
PORTVERSION=	0.35
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/K/KE/KEICHNER/
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Reading XML and providing path information based on a pull-parser

RUN_DEPENDS=	p5-XML-Parser>=0:${PORTSDIR}/textproc/p5-XML-Parser
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	XML::Reader.3 XML::Reader_de.3 XML::Reader_fr.3

.include <bsd.port.mk>
