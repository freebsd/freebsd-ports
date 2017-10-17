# Created by: lx
# $FreeBSD$

PORTNAME=	clusterssh
DISTVERSIONPREFIX=	release-
DISTVERSION=	4.10_02
PORTREVISION=	1
CATEGORIES=	security net

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Controls multiple hosts simultaneously via xterms and ssh

LICENSE=	GPLv2

BUILD_DEPENDS=	p5-File-Which>=0:sysutils/p5-File-Which \
		p5-Readonly>=0:devel/p5-Readonly \
		p5-Test-Pod>=0:devel/p5-Test-Pod \
		p5-Test-Pod-Coverage>=0:devel/p5-Test-Pod-Coverage \
		p5-Test-Trap>=0:devel/p5-Test-Trap \
		p5-Module-Manifest>=0:devel/p5-Module-Manifest \
		p5-File-Slurp>=0:devel/p5-File-Slurp \
		p5-Capture-Tiny>0:devel/p5-Capture-Tiny \
		p5-Exception-Class>=0:devel/p5-Exception-Class \
		p5-Try-Tiny>=0:lang/p5-Try-Tiny \
		p5-Tk>=0:x11-toolkits/p5-Tk \
		p5-Sort-Naturally>=1:textproc/p5-Sort-Naturally \
		p5-X11-Protocol>=0:x11/p5-X11-Protocol \
		p5-X11-Protocol-Other>=0:x11/p5-X11-Protocol-Other \
		xterm:x11/xterm
RUN_DEPENDS=	p5-Tk>=0:x11-toolkits/p5-Tk \
		p5-X11-Protocol>=0:x11/p5-X11-Protocol \
		p5-X11-Protocol-Other>=0:x11/p5-X11-Protocol-Other \
		p5-Exception-Class>=0:devel/p5-Exception-Class \
		p5-Try-Tiny>=0:lang/p5-Try-Tiny \
		p5-Sort-Naturally>=1:textproc/p5-Sort-Naturally \
		xterm:x11/xterm
TEST_DEPENDS=	p5-CPAN-Changes>=0:devel/p5-CPAN-Changes \
		p5-Test-Differences>=0:devel/p5-Test-Differences \
		p5-Test-PerlTidy>=0:devel/p5-Test-PerlTidy

USES=		perl5
USE_GITHUB=	yes
USE_PERL5=	modbuild

GH_ACCOUNT=	duncs

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	BASH

post-install-BASH-off:
	@${RM} ${STAGEDIR}${PREFIX}/bin/clusterssh_bash_completion.dist

post-install-BASH-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d
	${MV} ${STAGEDIR}${PREFIX}/bin/clusterssh_bash_completion.dist \
		${STAGEDIR}${PREFIX}/etc/bash_completion.d/clusterssh

.include <bsd.port.mk>
