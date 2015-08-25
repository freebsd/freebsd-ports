# Created by: brix@FreeBSD.org
# $FreeBSD$

PORTNAME=	Authen-DecHpwd
PORTVERSION=	2.006
PORTREVISION=	2
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl module for DEC VMS password hashing

LICENSE=	GPLv1

BUILD_DEPENDS=	p5-Scalar-String>=0:${PORTSDIR}/devel/p5-Scalar-String \
		p5-Data-Integer>=0:${PORTSDIR}/devel/p5-Data-Integer \
		p5-Digest-CRC>=0:${PORTSDIR}/security/p5-Digest-CRC
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Authen/DecHpwd/DecHpwd.so

.include <bsd.port.mk>
