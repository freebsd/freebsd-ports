# New ports collection makefile for:	p5-XML-SimpleObject-LibXML
# Date created:				02 September 2003
# Whom:	      				Foxfair Hu <foxfair@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	XML-SimpleObject-LibXML
PORTVERSION=	0.59
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	XML
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A simple(r) object representation of an XML::LibXML DOM object

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/XML/LibXML.pm:${PORTSDIR}/textproc/p5-XML-LibXML \
		${SITE_PERL}/XML/SimpleObject.pm:${PORTSDIR}/textproc/p5-XML-SimpleObject

PERL_CONFIGURE=	YES

MAN3=		XML::SimpleObject::LibXML.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
IGNORE=		This port requires perl 5.6.x or later. Install lang/perl5 then try again
.endif

.include <bsd.port.post.mk>
