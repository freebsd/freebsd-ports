# Created by: Vivek Khera <vivek@khera.org>
# $FreeBSD$

PORTNAME=	CSS-Simple
PORTVERSION=	3220
CATEGORIES=	textproc www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	vivek@khera.org
COMMENT=	Interface through which to read/write/manipulate CSS files

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Tie-IxHash>=0:devel/p5-Tie-IxHash
RUN_DEPENDS=	p5-Tie-IxHash>=0:devel/p5-Tie-IxHash

USES=		perl5
USE_PERL5=	configure

PLIST_FILES=	%%SITE_PERL%%/CSS/Simple.pm \
		%%PERL5_MAN3%%/CSS::Simple.3.gz \

.include <bsd.port.mk>
