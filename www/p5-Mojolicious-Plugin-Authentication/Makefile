# Created by: Mathieu Arnold <mat@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Mojolicious-Plugin-Authentication
PORTVERSION=	1.26
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	mat@FreeBSD.org
COMMENT=	Mojolicious plugin to make authentication a bit easier

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Mojolicious>=0:${PORTSDIR}/www/p5-Mojolicious
RUN_DEPENDS=	p5-Mojolicious>=0:${PORTSDIR}/www/p5-Mojolicious

USES=	perl5
USE_PERL5=	configure

post-patch:
	@${RM} ${WRKSRC}/README.pod

.include <bsd.port.mk>
