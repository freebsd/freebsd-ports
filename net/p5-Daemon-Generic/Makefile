PORTNAME=	Daemon-Generic
PORTVERSION=	0.85
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Framework to provide start/stop/reload for a daemon

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-File-Flock>=0:devel/p5-File-Flock \
		p5-File-Slurp>=0:devel/p5-File-Slurp \
		p5-AnyEvent>=0,1:devel/p5-AnyEvent \
		p5-Event>=0:devel/p5-Event \
		p5-Eval-LineNumbers>=0:devel/p5-Eval-LineNumbers

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
