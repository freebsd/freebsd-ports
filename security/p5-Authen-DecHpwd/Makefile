# Created by: brix@FreeBSD.org
# $FreeBSD$

PORTNAME=	Authen-DecHpwd
PORTVERSION=	2.006
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	brix@FreeBSD.org
COMMENT=	Perl module for DEC VMS password hashing

BUILD_DEPENDS=	p5-Scalar-String>=0:${PORTSDIR}/devel/p5-Scalar-String \
		p5-Data-Integer>=0:${PORTSDIR}/devel/p5-Data-Integer \
		p5-Digest-CRC>=0:${PORTSDIR}/security/p5-Digest-CRC
RUN_DEPENDS:=	${BUILD_DEPENDS}

LICENSE=	GPLv2
USES=		perl5
USE_PERL5=	modbuild

MAN3=	Authen::DecHpwd.3

NO_STAGE=	yes
.include <bsd.port.mk>
