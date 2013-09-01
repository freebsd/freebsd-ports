# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	BSD-Process
PORTVERSION=	0.06
CATEGORIES=	sysutils perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DLAND
PKGNAMEPREFIX=	p5-

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Information about running processes on BSD platforms

BUILD_DEPENDS=	p5-Class-Accessor>=0:${PORTSDIR}/devel/p5-Class-Accessor
RUN_DEPENDS=	p5-Class-Accessor>=0:${PORTSDIR}/devel/p5-Class-Accessor

USES=		perl5 shebangfix
USE_PERL5=	configure
SHEBANG_FILES=	eg/*

MAN3=	BSD::Process.3

post-install:
.for script in procinfo showprocattr topten
	@${INSTALL_SCRIPT} ${WRKSRC}/eg/${script} ${PREFIX}/bin
.endfor

.include <bsd.port.mk>
