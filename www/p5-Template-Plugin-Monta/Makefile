# Created by: TAKAHASHI Kaoru <kaoru@kaisei.org>
# $FreeBSD$

PORTNAME=	Template-Plugin-Monta
PORTVERSION=	0.03
PORTREVISION=	1
CATEGORIES=	www textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Template-Toolkit plugin to Monta Method

BUILD_DEPENDS=	p5-Template-Toolkit>=0:www/p5-Template-Toolkit
RUN_DEPENDS:=	${BUILD_DEPENDS} \
		p5-Acme-Monta>=0:www/p5-Acme-Monta

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
