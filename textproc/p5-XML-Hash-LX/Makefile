# New ports collection makefile for:	p5-XML-Hash-LX
# Date created:				09 Dec, 2009
# Whom:					Wen Heping <wen@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	XML-Hash-LX
PORTVERSION=	0.06
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Convert hash to xml and xml to hash using LibXML

BUILD_DEPENDS=	p5-lib-abs>=0.90:${PORTSDIR}/devel/p5-lib-abs \
		p5-XML-LibXML>=0:${PORTSDIR}/textproc/p5-XML-LibXML
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		XML::Hash::LX.3

.include <bsd.port.mk>
