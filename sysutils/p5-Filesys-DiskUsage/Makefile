# Created by: Alex Deiter <tiamat@komi.mts.ru>
# $FreeBSD$

PORTNAME=	Filesys-DiskUsage
PORTVERSION=	0.08
PORTREVISION=	1
CATEGORIES=	sysutils perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	culot@FreeBSD.org
COMMENT=	Perl equivalent of du(1)

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

TEST_DEPENDS=	p5-Test-Warn>0:devel/p5-Test-Warn

USES=		perl5
USE_PERL5=	configure

post-patch:
	@${RM} ${WRKSRC}/lib/Filesys/DiskUsage.pm.orig

.include <bsd.port.mk>
