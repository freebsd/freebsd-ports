# Created by: Alexander Y. Grigoryev <alexander.4mail@gmail.com>
# $FreeBSD$

PORTNAME=	File-KeePass
PORTVERSION=	2.03
PORTREVISION=	1
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	alexander.4mail@gmail.com
COMMENT=	Interface to KeePassX, KeePass 1.x and 2.x database files

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Crypt-Rijndael>=1.0:security/p5-Crypt-Rijndael \
		p5-MIME-Base64>=1.0:converters/p5-MIME-Base64
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
