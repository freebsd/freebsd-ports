# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	Pod-DocBook
PORTVERSION=	1.2
PORTREVISION=	2
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:NANDU
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Convert Pod data to DocBook SGML

BUILD_DEPENDS=	p5-podlators>=0:${PORTSDIR}/textproc/p5-podlators \
		p5-Text-Tabs+Wrap>=0:${PORTSDIR}/textproc/p5-Text-Tabs+Wrap
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
