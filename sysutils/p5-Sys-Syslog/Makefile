# $FreeBSD$

PORTNAME=	Sys-Syslog
PORTVERSION=	0.35
CATEGORIES=	sysutils perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl interface to the UNIX syslog(3) calls

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

MAKE_JOBS_UNSAFE=	yes
USES=		perl5
USE_PERL5=	configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Sys/Syslog/Syslog.so

.include <bsd.port.mk>
