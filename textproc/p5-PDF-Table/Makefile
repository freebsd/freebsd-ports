# New Ports collection makefile for:	p5-PDF-Table
# Date created:				May 22, 2009
# Whom:					scheidell@secnap.net
#
# $FreeBSD$
#

PORTNAME=	PDF-Table
PORTVERSION=	0.9.4
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	scheidell@secnap.net
COMMENT=	A utility class for building table layouts in a PDF::API2 object

BUILD_DEPENDS=	p5-PDF-API2>=0:${PORTSDIR}/textproc/p5-PDF-API2
RUN_DEPENDS=	p5-PDF-API2>=0:${PORTSDIR}/textproc/p5-PDF-API2

PERL_CONFIGURE=	yes

MAN3=		PDF::Table.3

.include <bsd.port.mk>
