# New ports collection makefile for:	p5-libsoldout
# Date created:				2012-07-22
# Whom:					Rodrigo OSORIO <rodrigo@bebik.net>
#
# $FreeBSD$
#

PORTNAME=	libsoldout
PORTVERSION=	0.02
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:ROS
PKGNAMEPREFIX=	p5-

MAINTAINER=	rodrigo@bebik.net
COMMENT=	Convert Markdown text in (X)HTML

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

LIB_DEPENDS=	soldout:${PORTSDIR}/textproc/libsoldout

PERL_CONFIGURE=	5.10.0+
USE_LDCONFIG=	yes

MAN3=		libsoldout.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501200
TEST_DEPENDS+=	p5-Test-Simple>=0.94:${PORTSDIR}/devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>
