# Created by: Anton Berezin <tobez@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Text-Diff
PORTVERSION=	1.41
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Text::Diff - Perform diffs on files and record sets

COMMON_DEPENDS=	p5-Algorithm-Diff>=1.19:${PORTSDIR}/devel/p5-Algorithm-Diff
BUILD_DEPENDS=	${COMMON_DEPENDS}
RUN_DEPENDS=	${COMMON_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=		Text::Diff.3 Text::Diff::Config.3 Text::Diff::Table.3

.include <bsd.port.mk>
