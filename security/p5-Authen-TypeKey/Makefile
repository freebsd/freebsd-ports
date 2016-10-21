# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	Authen-TypeKey
PORTVERSION=	0.05
PORTREVISION=	3
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	TypeKey authentication verification

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Class-ErrorHandler>=0:devel/p5-Class-ErrorHandler \
		p5-Digest-SHA1>=0:security/p5-Digest-SHA1 \
		p5-libwww>=0:www/p5-libwww \
		p5-Module-Install>0:devel/p5-Module-Install
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_ARCH=	yes
USE_PERL5=	configure
USES=		perl5

post-patch:
	# Really old M::I code
	${RM} -r ${WRKSRC}/inc

.include <bsd.port.mk>
