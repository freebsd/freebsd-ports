# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	BSD-Process
PORTVERSION=	0.07
PORTREVISION=	1
CATEGORIES=	sysutils perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DLAND
PKGNAMEPREFIX=	p5-

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Information about running processes on BSD platforms

BUILD_DEPENDS=	p5-Class-Accessor>=0:devel/p5-Class-Accessor
RUN_DEPENDS=	p5-Class-Accessor>=0:devel/p5-Class-Accessor

USES=		perl5 shebangfix
USE_PERL5=	configure
SHEBANG_FILES=	eg/*

post-install:
.for script in procinfo showprocattr topten
	@${INSTALL_SCRIPT} ${WRKSRC}/eg/${script} ${STAGEDIR}${PREFIX}/bin
.endfor

.include <bsd.port.mk>
