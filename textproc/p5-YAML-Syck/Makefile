# New ports collection makefile for:	textproc/p5-YAML-Syck
# Date created:				28 December 2005
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	YAML-Syck
PORTVERSION=	1.07
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Fast, lightweight YAML and JSON loader and dumper

PERL_CONFIGURE=	yes
CONFIGURE_ARGS+=	< /dev/null

MAN3=		JSON::Syck.3 YAML::Syck.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500700
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Storable.pm:${PORTSDIR}/devel/p5-Storable \
		p5-Scalar-List-Utils>0:${PORTSDIR}/lang/p5-Scalar-List-Utils
BUILD_DEPENDS=	${RUN_DEPENDS}
.endif

.include <bsd.port.post.mk>
