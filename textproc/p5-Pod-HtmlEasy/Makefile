# Created by: Wen Heping <wen@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Pod-HtmlEasy
PORTVERSION=	1.0108
PORTREVISION=	2
CATEGORIES=	textproc devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Generate personalized HTML from PODs

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-File-Slurp>=9999.13:devel/p5-File-Slurp \
		p5-IPC-Run>=0.8:devel/p5-IPC-Run \
		p5-Exporter-Easy>=0:devel/p5-Exporter-Easy \
		p5-Readonly>=1.03:devel/p5-Readonly \
		p5-Regexp-Common>=2.12:textproc/p5-Regexp-Common \
		p5-Pod-Escapes>=0:textproc/p5-Pod-Escapes
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5 tar:tgz
USE_PERL5=	configure

.include <bsd.port.mk>
