# Created by: Mahlon E. Smith <mahlon@martini.nu>
# $FreeBSD$

PORTNAME=	BSD-Jail-Object
PORTVERSION=	0.02
PORTREVISION=	2
CATEGORIES=	sysutils perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	mahlon@martini.nu
COMMENT=	An object oriented perl interface to jail(2)

BUILD_DEPENDS=	p5-Inline>=0:${PORTSDIR}/devel/p5-Inline

MAKE_JOBS_UNSAFE=	yes

USES=		perl5
USE_PERL5=	configure

MAN3=		BSD::Jail::Object.3

NO_STAGE=	yes
.include <bsd.port.mk>
