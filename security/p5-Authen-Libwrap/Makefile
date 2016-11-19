# Created by: Zach Thompson <hideo@lastamericanempire.com>
# $FreeBSD$

PORTNAME=	Authen-Libwrap
PORTVERSION=	0.23
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Authen::Libwrap - access to TCP Wrappers library

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

TEST_DEPENDS=	p5-Test-Exception>0:devel/p5-Test-Exception

USES=		perl5
USE_PERL5=	modbuild

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Authen/Libwrap/Libwrap.so

.include <bsd.port.mk>
