# New ports collection makefile for:	p5-Text-Extract-Word
# Date created:				April 07 2010
# Whom:					jupengfei <jupengfei@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	Text-Extract-Word
PORTVERSION=	0.01
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	jupengfei@gmail.com
COMMENT=	A simple module for extracting the text from a Microsoft Word file

BUILD_DEPENDS=	${SITE_PERL}/parent.pm:${PORTSDIR}/devel/p5-parent \
		${SITE_PERL}/ExtUtils/MakeMaker.pm:${PORTSDIR}/devel/p5-ExtUtils-MakeMaker \
		${SITE_PERL}/OLE/Storage_Lite.pm:${PORTSDIR}/devel/p5-OLE-Storage_Lite
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	YES

MAN3=		Text::Extract::Word.3

.include <bsd.port.mk>
