# $FreeBSD$

PORTNAME=	Giovanni
PORTVERSION=	1.12
CATEGORIES=	sysutils perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:NORBU
PKGNAMEPREFIX=	p5-

MAINTAINER=	dch@skunkwerks.at
COMMENT=	PERL-based software deployment tool inspired by capistrano

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	\
		p5-Config-GitLike>=0:devel/p5-Config-GitLike \
		p5-Expect>=0:lang/p5-Expect \
		p5-Git-Repository>=0:devel/p5-Git-Repository \
		p5-LWP-Protocol-https>=0:www/p5-LWP-Protocol-https \
		p5-libwww>=0:www/p5-libwww \
		p5-Mouse>=0:devel/p5-Mouse \
		p5-Net-OpenSSH>=0:net/p5-Net-OpenSSH


NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
