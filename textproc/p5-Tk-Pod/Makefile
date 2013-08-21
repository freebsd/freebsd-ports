# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Tk-Pod
PORTVERSION=	0.9941
CATEGORIES=	textproc tk perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Simple Pod browser with hypertext capabilities in a Toplevel widget

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Tk>=800.004:${PORTSDIR}/x11-toolkits/p5-Tk
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_PERL5=	configure
USES=		perl5

MAN1=		tkmore.1 \
		tkpod.1
MAN3=		Tk::More.3 \
		Tk::Pod.3 \
		Tk::Pod::Cache.3 \
		Tk::Pod::FindPods.3 \
		Tk::Pod::Search.3 \
		Tk::Pod::Search_db.3 \
		Tk::Pod::SimpleBridge.3 \
		Tk::Pod::Text.3 \
		Tk::Pod::Tree.3 \
		Tk::Pod::Util.3 \
		Tk::Pod_usage.3

.include <bsd.port.mk>
