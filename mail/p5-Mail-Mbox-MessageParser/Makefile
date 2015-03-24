# Created by: Cheng-Lung Sung <clsung@dragon2.net>
# $FreeBSD$

PORTNAME=	Mail-Mbox-MessageParser
PORTVERSION=	1.5100
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Fast and simple mbox folder reader

LICENSE=	GPLv2

BUILD_DEPENDS=	p5-FileHandle-Unget>=0:${PORTSDIR}/devel/p5-FileHandle-Unget
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Text-Diff>=0:${PORTSDIR}/textproc/p5-Text-Diff

USES=		perl5
USE_PERL5=	configure

post-patch:
	# If upstream adds a =cut in a future release, this patch will break configure
	@${REINPLACE_CMD} -e '/=encoding utf-8/d' ${WRKSRC}/inc/Sort/Versions.pm

.include <bsd.port.mk>
