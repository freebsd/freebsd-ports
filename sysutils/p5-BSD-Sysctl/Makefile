# Created by: chinsan <chinsan.tw@gmail.com>
# $FreeBSD$

PORTNAME=	BSD-Sysctl
PORTVERSION=	0.12
CATEGORIES=	sysutils perl5
USE_GITHUB=	yes
GH_ACCOUNT=	glebius
GH_TAGNAME=	v0.12

MAINTAINER=	glebius@FreeBSD.org
COMMENT=	Fetch sysctl values from BSD-like systems

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

USES=		perl5
USE_PERL5=	configure

pre-install:
	${STRIP_CMD} ${WRKSRC}/blib/arch/auto/BSD/Sysctl/Sysctl.so

.include <bsd.port.mk>
