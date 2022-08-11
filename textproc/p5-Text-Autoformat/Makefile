PORTNAME=	Text-Autoformat
PORTVERSION=	1.670.000
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:NEILB
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:C/0\.(000)$//}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Automatic and manual text wrapping and reformatting

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Text-Reform>=1.11:textproc/p5-Text-Reform

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
