PORTNAME=	CSP
PORTVERSION=	0.34
PORTREVISION=	1
CATEGORIES=	security perl5
MASTER_SITES=	ftp://ftp.it.su.se/pub/users/leifj/ \
		http://redundancy.redundancy.org/mirror/
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl tool for managing Certificate Authorities
WWW=		http://devel.it.su.se/projects/CSP/

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Date-Calc>=0:devel/p5-Date-Calc \
		p5-Term-Prompt>=0:devel/p5-Term-Prompt \
		p5-IPC-Run>=0:devel/p5-IPC-Run

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
