PORTNAME=	Text-Table-TickitWidget
PORTVERSION=	0.001
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	View table data on the terminal using Tickit::Widget::Table

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Tickit>=0:devel/p5-Tickit \
		p5-Tickit-Widget-Table>=0:devel/p5-Tickit-Widget-Table

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
