# New ports collection makefile for:	sysutils/p5-Filesys-DiskSpace
# Date created:				26 February 2001
# Whom:					Anton Berezin <tobez@tobez.org>
#
# $FreeBSD$
#

PORTNAME=	Filesys-DiskSpace
PORTVERSION=	0.05
CATEGORIES=	sysutils perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Filesys
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Perl equivalent of statfs(2)

PERL_CONFIGURE=	yes

MAN3=		Filesys::DiskSpace.3

post-patch:
	@${FIND} ${WRKSRC} -name "*\.orig" -delete

.include <bsd.port.mk>
