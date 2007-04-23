# New ports collection makefile for:	p5-Kwiki-Archive-Rcs
# Date created:				Jul 24 2004
# Whom:	      				Cheng-Lung Sung <clsung@dragon2.net>
#
# $FreeBSD$
#

PORTNAME=	Kwiki-Archive-Rcs
PORTVERSION=	0.15
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Kwiki
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Kwiki Page Archival Using RCS

BUILD_DEPENDS=	p5-Kwiki>=0.38:${PORTSDIR}/www/p5-Kwiki
RUN_DEPENDS=	${BUILD_DEPENDS}

DEPRECATED=		Already bundled in www/p5-Kwiki (0.39 or latter)
EXPIRATION_DATE=	2007-07-28
BROKEN=		${DEPRECATED}

PERL_CONFIGURE=	yes

MAN3=		Kwiki::Archive::Rcs.3

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
