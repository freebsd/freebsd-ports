# Created by: Cheng-Lung Sung <clsung@FreeBSD.org>
# $FreeBSD$

PORTNAME=	XML-RSS-Feed
PORTVERSION=	2.40
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:S/0$//}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Persistent XML RSS encapsulation

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Clone>=0:${PORTSDIR}/devel/p5-Clone \
		p5-HTML-Parser>=0:${PORTSDIR}/www/p5-HTML-Parser \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-XML-RSS>=0:${PORTSDIR}/textproc/p5-XML-RSS
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
