# New ports collection makefile for:	p5-Kwiki-NavigationToolbar
# Date created:				Jun 4 2005
# Whom:	      				brian
#
# $FreeBSD$
#

PORTNAME=	Kwiki-NavigationToolbar
PORTVERSION=	0.02
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Kwiki
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Kwiki navigation toolbar, works well with Kwiki-ColumnLayout

BUILD_DEPENDS=	${SITE_PERL}/Kwiki.pm:${PORTSDIR}/www/p5-Kwiki
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Kwiki::NavigationToolbar.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
IGNORE=		This port requires perl 5.6.x or later. Install lang/perl5 then try again
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
