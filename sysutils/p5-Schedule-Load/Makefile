PORTNAME=	Schedule-Load
PORTVERSION=	3.064
PORTREVISION=	1
CATEGORIES=	sysutils perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Load distribution and status across multiple host machines

LICENSE=	ART20 LGPL3
LICENSE_COMB=	dual
LICENSE_FILE_ART20=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Proc-ProcessTable>=0.40:devel/p5-Proc-ProcessTable \
		p5-Unix-Processors>=2.02:sysutils/p5-Unix-Processors \
		p5-IPC-Locker>=1.41:devel/p5-IPC-Locker

MAKE_JOBS_UNSAFE=	yes

USES=		perl5
USE_PERL5=	configure

OPTIONS_DEFINE=	EXAMPLES

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/init.d
	${INSTALL_SCRIPT} ${WRKSRC}/init.d/* ${STAGEDIR}${EXAMPLESDIR}/init.d

.include <bsd.port.mk>
