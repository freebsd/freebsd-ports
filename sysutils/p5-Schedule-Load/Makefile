# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	Schedule-Load
PORTVERSION=	3.064
CATEGORIES=	sysutils perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Load distribution and status across multiple host machines

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	p5-Proc-ProcessTable>=0.40:${PORTSDIR}/devel/p5-Proc-ProcessTable \
		p5-Unix-Processors>=2.02:${PORTSDIR}/sysutils/p5-Unix-Processors \
		p5-IPC-Locker>=1.41:${PORTSDIR}/devel/p5-IPC-Locker
BUILD_DEPENDS:=	${RUN_DEPENDS}

MAKE_JOBS_UNSAFE=	yes

USES=		perl5
USE_PERL5=	configure

post-install:
.ifndef(NOPORTEXAMPLES)
	@${ECHO_MSG} "===>   Installing examples for ${PKGNAME}"
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/init.d
	${INSTALL_SCRIPT} ${WRKSRC}/init.d/* ${STAGEDIR}${EXAMPLESDIR}/init.d
.endif

.include <bsd.port.mk>
