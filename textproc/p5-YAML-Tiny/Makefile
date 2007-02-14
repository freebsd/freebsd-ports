# New ports collection makefile for:	p5-YAML-Tiny
# Date created:		2006-07-17
# Whom:			Yuan-Chung Hsiao <ychsiao@ychsiao.org>
#
# $FreeBSD$
#

PORTNAME=	YAML-Tiny
PORTVERSION=	1.03
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	YAML
PKGNAMEPREFIX=	p5-

MAINTAINER=	ychsiao@ychsiao.org
COMMENT=	YAML::Tiny - Read/Write YAML files with as little code as possible

PERL_CONFIGURE=	yes

MAN3=	YAML::Tiny.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601 # File::Spec require at least 0.8
IGNORE=		requires perl 5.6.x or later. Install lang/perl5.8 then try again
.endif

.if ${PERL_LEVEL} < 500801
BUILD_DEPENDS=	p5-Test-Base>=0.47:${PORTSDIR}/devel/p5-Test-Base
.endif

.include <bsd.port.post.mk>
