# New ports collection makefile for:	p5-Text-Extract-Word
# Date created:				April 07 2010
# Whom:					jupengfei <jupengfei@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	Text-Extract-Word
PORTVERSION=	0.03
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	culot@FreeBSD.org
COMMENT=	A simple module for extracting the text from a Microsoft Word file

LICENSE=	ART20

BUILD_DEPENDS=	${SITE_PERL}/OLE/Storage_Lite.pm:${PORTSDIR}/devel/p5-OLE-Storage_Lite
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	YES

MAN3=		Text::Extract::Word.3

.include <bsd.port.mk>
