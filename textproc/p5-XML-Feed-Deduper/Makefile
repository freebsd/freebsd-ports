# Created by: TERAMOTO Masahiro <markun@onohara.to>
# $FreeBSD$

PORTNAME=	XML-Feed-Deduper
PORTVERSION=	0.06
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	markun@onohara.to
COMMENT=	Remove duplicated entries from feed

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Mouse>=1.08:${PORTSDIR}/devel/p5-Any-Moose \
		p5-XML-Feed>=0.41:${PORTSDIR}/textproc/p5-XML-Feed
RUN_DEPENDS=	p5-Mouse>=1.08:${PORTSDIR}/devel/p5-Any-Moose \
		p5-XML-Feed>=0.41:${PORTSDIR}/textproc/p5-XML-Feed

USES=		perl5
USE_PERL5=	modbuild

MAN3=		XML::Feed::Deduper.3

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501400
TEST_DEPENDS+=	p5-Test-Simple>=0.98:${PORTSDIR}/devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>
