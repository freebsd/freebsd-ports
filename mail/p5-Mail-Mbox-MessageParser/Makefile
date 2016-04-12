# Created by: Cheng-Lung Sung <clsung@dragon2.net>
# $FreeBSD$

PORTNAME=	Mail-Mbox-MessageParser
PORTVERSION=	1.5105
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Fast and simple mbox folder reader

LICENSE=	GPLv2

BUILD_DEPENDS+=	p5-File-Slurp>=0:devel/p5-File-Slurp \
		p5-FileHandle-Unget>=0:devel/p5-FileHandle-Unget \
		p5-URI>=0:net/p5-URI
RUN_DEPENDS=	p5-FileHandle-Unget>=0:devel/p5-FileHandle-Unget
TEST_DEPENDS=	p5-Text-Diff>=0:textproc/p5-Text-Diff

USES=		perl5
USE_PERL5=	configure

CONFIGURE_ARGS= < /dev/null

.include <bsd.port.mk>
