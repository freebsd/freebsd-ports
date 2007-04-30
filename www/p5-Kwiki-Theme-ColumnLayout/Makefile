# New ports collection makefile for:	p5-Kwiki-Theme-ColumnLayout
# Date created:				Jan 20 2005
# Whom:	      				clsung
#
# $FreeBSD$
#

PORTNAME=	Kwiki-Theme-ColumnLayout
PORTVERSION=	0.08
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Kwiki
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Kwiki Theme with two/three column layout

BUILD_DEPENDS=	${SITE_PERL}/Kwiki.pm:${PORTSDIR}/www/p5-Kwiki
RUN_DEPENDS=	${BUILD_DEPENDS}

DEPRECATED=		already bundled in www/p5-Kwiki (0.39 or latter)
EXPIRATION_DATE=	2007-07-28
IGNORE=		${DEPRECATED}

PERL_CONFIGURE=	yes

MAN3=		Kwiki::Theme::ColumnLayout.3

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
