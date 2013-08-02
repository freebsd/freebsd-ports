# New ports collection makefile for:	p5-XML-XSLT
# Date created:				May 26 2001
# Whom:					vanilla
#
# $FreeBSD$
#

PORTNAME=	XML-XSLT
PORTVERSION=	0.48
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	XML::XSLT - A perl module for processing XSLT

BUILD_DEPENDS=	p5-XML-DOM>=0:${PORTSDIR}/textproc/p5-XML-DOM
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN1=		xslt-parser.1
MAN3=		XML::XSLT.3

.include <bsd.port.mk>
