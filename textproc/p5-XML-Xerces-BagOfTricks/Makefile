# ex:ts=8
# Ports collection makefile for:	p5-XML-Xerces-BagOfTricks
# Date created:			19 January 2004
# Whom:				Scott McWhirter <scott@surreytech.co.uk>
#
# $FreeBSD$
#

PORTNAME=	XML-Xerces-BagOfTricks
PORTVERSION=	0.03
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	XML
PKGNAMEPREFIX=	p5-

MAINTAINER=	scott@surreytech.co.uk
COMMENT=	Provide a bag of tricks for users of XML::Xerces DOM API

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/XML/Xerces.pm:${PORTSDIR}/textproc/p5-XML-Xerces
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	XML::Xerces::BagOfTricks.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500801
IGNORE=		Port requires perl 5.8.x or later. Install lang/perl5.8 then try again
.endif

.include <bsd.port.post.mk>
