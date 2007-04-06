# New ports collection makefile for:	sysutils/p5-Filesys-DiskUsage
# Date created:				20 September 2005
# Whom:					Alex Deiter <tiamat@komi.mts.ru>
#
# $FreeBSD$
#

PORTNAME=	Filesys-DiskUsage
PORTVERSION=	0.04
CATEGORIES=	sysutils perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Filesys
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl equivalent of du(1)

PERL_CONFIGURE=	yes

MAN3=		Filesys::DiskUsage.3

post-patch:
	@${RM} ${WRKSRC}/lib/Filesys/DiskUsage.pm.orig

.include <bsd.port.mk>
