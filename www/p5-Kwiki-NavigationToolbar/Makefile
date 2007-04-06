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

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
