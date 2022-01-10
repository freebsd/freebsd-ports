# Created by: Travis Campbell <hcoyote@ghostar.org>

PORTNAME=	HTML-Diff
PORTVERSION=	0.561
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl module for finding changes between two strings of HTML

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Algorithm-Diff>=0:devel/p5-Algorithm-Diff

USES=		perl5
USE_PERL5=	configure

CONFLICTS_INSTALL=	rubygem-diff-lcs # bin/htmldiff

.include <bsd.port.mk>
