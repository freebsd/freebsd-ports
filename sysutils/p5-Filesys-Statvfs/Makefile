# New ports collection makefile for:	p5-Filesys-Statvfs
# Date created:				31 May 2006
# Whom:	      				Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Filesys-Statvfs
PORTVERSION=	0.80
CATEGORIES=	sysutils perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Filesys
PKGNAMEPREFIX=	p5-

MAINTAINER=	pirzyk@freebsd.org
COMMENT=	Perl extension for statvfs() and fstatvfs()

PERL_CONFIGURE=	yes

MAN3=		Filesys::Statvfs.3

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
IGNORE=	requires statvfs() which is not available before FreeBSD-5*
.endif

.include <bsd.port.post.mk>
