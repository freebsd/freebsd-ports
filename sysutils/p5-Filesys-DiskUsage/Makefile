# Created by: Alex Deiter <tiamat@komi.mts.ru>
# $FreeBSD$

PORTNAME=	Filesys-DiskUsage
PORTVERSION=	0.05
CATEGORIES=	sysutils perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	culot@FreeBSD.org
COMMENT=	Perl equivalent of du(1)

USES=		perl5
USE_PERL5=	configure

MAN3=		Filesys::DiskUsage.3

NO_STAGE=	yes
post-patch:
	@${RM} ${WRKSRC}/lib/Filesys/DiskUsage.pm.orig

.include <bsd.port.mk>
