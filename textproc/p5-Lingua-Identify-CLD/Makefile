# Created by: Gasol Wu <gasol.wu@gmail.com>
# $FreeBSD$

PORTNAME=	Lingua-Identify-CLD
PORTVERSION=	0.09
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	gasol.wu@gmail.com
COMMENT=	Interface to Chrome language detection library

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libcld.so:devel/cld
BUILD_DEPENDS=	p5-Config-AutoConf>=0.16:devel/p5-Config-AutoConf \
		p5-ExtUtils-CBuilder>0.27:devel/p5-ExtUtils-CBuilder \
		p5-ExtUtils-ParseXS>=0:devel/p5-ExtUtils-ParseXS \
		p5-ExtUtils-LibBuilder>=0.02:devel/p5-ExtUtils-LibBuilder
RUN_DEPENDS=	p5-XSLoader>=0:devel/p5-XSLoader

USES=		perl5
USE_PERL5=	modbuild

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Lingua/Identify/CLD/CLD.so

.include <bsd.port.mk>
