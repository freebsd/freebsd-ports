# New ports collection makefile for:	sysutils/p5-BSD-Jail-Object
# Date created:		2006-08-07
# Whom:			Mahlon E. Smith <mahlon@martini.nu>
#
# $FreeBSD$
#

PORTNAME=	BSD-Jail-Object
PORTVERSION=	0.02
CATEGORIES=	sysutils perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/M/MA/MAHLON
PKGNAMEPREFIX=	p5-

MAINTAINER=	mahlon@martini.nu
COMMENT=	An object oriented perl interface to jail(2)

BUILD_DEPENDS=\
	${SITE_PERL}/Inline.pm:${PORTSDIR}/devel/p5-Inline

PERL_CONFIGURE=	yes

MAN3=		BSD::Jail::Object.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500806
IGNORE=		requires perl 5.8.6 or later. Install lang/perl5.8 then try again
.endif

.if ${OSVERSION} < 503100 # ref: jail.h v1.17
IGNORE=		require xprison structure defined
.endif

.include <bsd.port.post.mk>
