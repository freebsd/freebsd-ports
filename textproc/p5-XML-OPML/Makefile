# Created by: ijliao
# $FreeBSD$

PORTNAME=	XML-OPML
PORTVERSION=	0.26
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Creates and updates OPML (Outline Processor Markup Language) files

BUILD_DEPENDS=	p5-XML-Parser>=0:${PORTSDIR}/textproc/p5-XML-Parser \
		p5-XML-SimpleObject>=0:${PORTSDIR}/textproc/p5-XML-SimpleObject
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
