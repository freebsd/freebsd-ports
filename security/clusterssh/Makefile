# Created by: lx
# $FreeBSD$

PORTNAME=	clusterssh
PORTVERSION=	4.01
CATEGORIES=	security net
MASTER_SITES=	SF/${PORTNAME}/2.%20ClusterSSH%20Series%204
DISTNAME=	App-ClusterSSH-${PORTVERSION}_01

MAINTAINER=	lx@FreeBSD.org
COMMENT=	Controls multiple hosts simultaneously via xterms and ssh

BUILD_DEPENDS=	p5-File-Which>=0:${PORTSDIR}/sysutils/p5-File-Which \
		p5-Readonly>=0:${PORTSDIR}/devel/p5-Readonly \
		p5-Test-Pod>=0:${PORTSDIR}/devel/p5-Test-Pod \
		p5-Test-Pod-Coverage>=0:${PORTSDIR}/devel/p5-Test-Pod-Coverage \
		p5-Test-Trap>=0:${PORTSDIR}/devel/p5-Test-Trap \
		p5-Module-Manifest>=0:${PORTSDIR}/devel/p5-Module-Manifest

RUN_DEPENDS=	p5-Tk>=0:${PORTSDIR}/x11-toolkits/p5-Tk \
		p5-X11-Protocol>=0:${PORTSDIR}/x11/p5-X11-Protocol \
		p5-Exception-Class>=0:${PORTSDIR}/devel/p5-Exception-Class \
		p5-Try-Tiny>=0:${PORTSDIR}/lang/p5-Try-Tiny

USE_PERL5=	yes
PERL_CONFIGURE=	yes

MAN1=		cssh.1

.include <bsd.port.mk>
