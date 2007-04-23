# New ports collection makefile for:	p5-Kwiki-NewPage
# Date created:		2004-08-28
# Whom:			Elvis Chiang <elvis@sslab.cs.ccu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	Kwiki-NewPage
PORTVERSION=	0.12
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Kwiki
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Kwiki New Page Plugin

BUILD_DEPENDS=	${SITE_PERL}/Kwiki.pm:${PORTSDIR}/www/p5-Kwiki
RUN_DEPENDS=	${BUILD_DEPENDS}

DEPRECATED=		Already bundled in www/p5-Kwiki (0.39 or latter)
EXPIRATION_DATE=	2007-07-28
BROKEN=		${DEPRECATED}

PERL_CONFIGURE=	yes

MAN3=		Kwiki::NewPage.3

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
