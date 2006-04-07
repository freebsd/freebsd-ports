# New ports collection makefile for:	textproc/p5-YAML-Syck
# Date created:				28 December 2005
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	YAML-Syck
PORTVERSION=	0.41
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	YAML
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Fast, lightweight YAML and JSON loader and dumper

BUILD_DEPENDS=	\
	p5-Storable>0:${PORTSDIR}/devel/p5-Storable
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		JSON::Syck.3 YAML::Syck.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		requires perl 5.6.0 or later. Install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
