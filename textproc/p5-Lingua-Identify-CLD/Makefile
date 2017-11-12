# Created by: Gasol Wu <gasol.wu@gmail.com>
# $FreeBSD$

PORTNAME=	Lingua-Identify-CLD
PORTVERSION=	0.09
PORTREVISION=	3
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	gasol.wu@gmail.com
COMMENT=	Interface to Chrome language detection library

LICENSE=	BSD3CLAUSE

DEPRECATED=	Depends on expired devel/cld
EXPIRATION_DATE=2017-12-12

BUILD_DEPENDS=	p5-Config-AutoConf>=0.17:devel/p5-Config-AutoConf \
		p5-ExtUtils-LibBuilder>=0.04:devel/p5-ExtUtils-LibBuilder
LIB_DEPENDS=	libcld.so:devel/cld

USES=		perl5
USE_PERL5=	modbuild

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Lingua/Identify/CLD/CLD.so

.include <bsd.port.mk>
