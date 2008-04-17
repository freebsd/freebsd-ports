# New ports collection makefile for:	p5-Fuse-Simple
# Date created:		2006-08-06
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Fuse-Simple
PORTVERSION=	1.00
CATEGORIES=	sysutils perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/N/NO/NOSEYNICK
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	Simple way to write filesystems in Perl using FUSE

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Fuse.pm:${PORTSDIR}/sysutils/p5-Fuse

PERL_CONFIGURE=	yes

MAN3=		Fuse::Simple.3

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 600000	# Inherited from sysutils/p5-Fuse
IGNORE=		depends on kernel module that requires FreeBSD 6 or later
.endif

.if ${PERL_LEVEL} < 500703
RUN_DEPENDS+=	${SITE_PERL}/Switch.pm:${PORTSDIR}/lang/p5-Switch
.endif

.include <bsd.port.post.mk>
