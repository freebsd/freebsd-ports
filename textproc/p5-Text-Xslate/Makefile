# Created by: Anton Berezin <tobez@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Text-Xslate
PORTVERSION=	3.3.3
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:SYOHEX
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	High performance template engine

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Data-MessagePack>=0.38:${PORTSDIR}/devel/p5-Data-MessagePack \
		p5-Mouse>=0.61:${PORTSDIR}/devel/p5-Mouse
RUN_DEPENDS:=	${BUILD_DEPENDS}

MAKE_JOBS_UNSAFE=	yes

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501600
BUILD_DEPENDS+=	p5-ExtUtils-MakeMaker>=6.59:${PORTSDIR}/devel/p5-ExtUtils-MakeMaker
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${SITE_ARCH}/auto/Text/Xslate/Xslate.so

.include <bsd.port.post.mk>
