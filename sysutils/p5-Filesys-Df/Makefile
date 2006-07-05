# New ports collection makefile for:	p5-Filesys-Df
# Date created:				31 May 2006
# Whom:	      				Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Filesys-Df
PORTVERSION=	0.92
CATEGORIES=	sysutils perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Filesys
PKGNAMEPREFIX=	p5-

MAINTAINER=	pirzyk@FreeBSD.org
COMMENT=	Perl extension for filesystem space

PERL_CONFIGURE=	yes

MAN3=		Filesys::Df.3

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
IGNORE=	requires statvfs() which is not available before FreeBSD-5*
.endif

.include <bsd.port.post.mk>
