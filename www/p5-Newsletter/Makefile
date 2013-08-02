# Created by: chinsan
# $FreeBSD$

PORTNAME=	Newsletter
PORTVERSION=	0.03.3
CATEGORIES=	www textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:KALELE
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Simple website based Newsletter interface

BUILD_DEPENDS=	p5-MIME-Explode>0:${PORTSDIR}/mail/p5-MIME-Explode \
		p5-MIME-Lite>0:${PORTSDIR}/mail/p5-MIME-Lite \
		p5-File-Type>0:${PORTSDIR}/devel/p5-File-Type
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=	Newsletter::Html.3 Newsletter::Html::Templ.3 Newsletter::Html::CSS.3 \
	Newsletter::Html::Upload.3 Newsletter.3

.include <bsd.port.mk>
