# New ports collection makefile for:	p5-Kwiki-Icons-Gnome
# Date created:				Feb 16 2005
# Whom:	      				Mark Foster <mark@foster.cc>
#
# $FreeBSD$
#

PORTNAME=	Kwiki-Icons-Gnome
PORTVERSION=	0.14
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Kwiki
PKGNAMEPREFIX=	p5-

MAINTAINER=	mark@foster.cc
COMMENT=	Kwiki Gnome Icons plugin

BUILD_DEPENDS=	${SITE_PERL}/Kwiki.pm:${PORTSDIR}/www/p5-Kwiki
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Kwiki::Icons::Gnome.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
IGNORE=		This port requires perl 5.6.x or later. Install lang/perl5 then try again
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
