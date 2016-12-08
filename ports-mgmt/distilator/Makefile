# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	distilator
PORTVERSION=	0.3
PORTREVISION=	1
CATEGORIES=	ports-mgmt perl5
MASTER_SITES=	LOCAL/ehaupt

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Command-line script to check the availability of a ports distfiles

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	p5-URI>=1.56:net/p5-URI \
		p5-libwww>=0:www/p5-libwww \
		p5-Parallel-ForkManager>=0:devel/p5-Parallel-ForkManager
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	yes

OPTIONS_DEFINE=	SSL
OPTIONS_DEFAULT=SSL

SSL_RUN_DEPENDS=	p5-Crypt-SSLeay>=0:security/p5-Crypt-SSLeay

.include <bsd.port.mk>
