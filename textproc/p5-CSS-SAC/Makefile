# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	CSS-SAC
PORTVERSION=	0.08
PORTREVISION=	1
CATEGORIES=	textproc perl5 www
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SAC CSS (Simple API for CSS) parser

BUILD_DEPENDS=	p5-Class-ArrayObjects>=0.04:${PORTSDIR}/devel/p5-Class-ArrayObjects
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

# Bareword "_out_" not allowed while "strict subs"
post-patch:
	@${REINPLACE_CMD} -e "s,_out_,'_out_',g" ${WRKSRC}/lib/CSS/SAC/TestWriter.pm
	@${FIND} ${WRKSRC} -name "*.bak" -delete

.include <bsd.port.mk>
