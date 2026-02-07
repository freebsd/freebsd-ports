PORTNAME=	HTML-Diff
PORTVERSION=	0.60
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module for finding changes between two strings of HTML
WWW=		https://github.com/neilb/html-diff

LICENSE=	ARTPERL10

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Algorithm-Diff>=0:devel/p5-Algorithm-Diff

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

CONFLICTS_INSTALL=	rubygem-diff-lcs # bin/htmldiff

PORTSCOUT=	skipv:0.561

.include <bsd.port.mk>
