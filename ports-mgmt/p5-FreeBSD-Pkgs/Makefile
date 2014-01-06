# Created by: Zane C, Bowers <vvelox@vvelox.net>
# $FreeBSD$

PORTNAME=	FreeBSD-Pkgs
PORTVERSION=	0.2.0
CATEGORIES=	ports-mgmt sysutils perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	vvelox@vvelox.net
COMMENT=	Parses the contents of FreeBSD package DB under /var/db/pkg

BUILD_DEPENDS=	p5-Error-Helper>=0:${PORTSDIR}/devel/p5-Error-Helper
RUN_DEPENDS=	p5-Error-Helper>=0:${PORTSDIR}/devel/p5-Error-Helper

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
