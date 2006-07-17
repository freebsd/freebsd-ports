# New ports collection makefile for:	p5-YAML-Tiny
# Date created:		2006-07-17
# Whom:			Yuan-Chung Hsiao <ychsiao@ychsiao.org>
#
# $FreeBSD$
#

PORTNAME=	YAML-Tiny
PORTVERSION=	0.05
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	YAML
PKGNAMEPREFIX=	p5-

MAINTAINER=	ychsiao@ychsiao.org
COMMENT=	YAML::Tiny - Read/Write YAML files with as little code as possible

BUILD_DEPENDS=	p5-Test-Base>=0.47:${PORTSDIR}/devel/p5-Test-Base
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	YAML::Tiny.3
.include <bsd.port.mk>
