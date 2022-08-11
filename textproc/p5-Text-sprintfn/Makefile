PORTNAME=	Text-sprintfn
PORTVERSION=	0.090
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	vvelox@vvelox.net
COMMENT=	Drop-in replacement for sprintf(), with named parameter support

BUILD_DEPENDS=	p5-Exporter>=5.57:devel/p5-Exporter
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

PLIST_FILES=	${SITE_MAN3_REL}/Text::sprintfn.3.gz \
		${SITE_PERL_REL}/Text/sprintfn.pm

.include <bsd.port.mk>
