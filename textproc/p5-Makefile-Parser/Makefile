# Created by: Anton Berezin <tobez@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Makefile-Parser
PORTVERSION=	0.216
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:AGENT
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Simple Perl parser for makefiles

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Class-Accessor>=0:devel/p5-Class-Accessor \
		p5-Class-Trigger>=0.13:devel/p5-Class-Trigger \
		p5-File-Slurp>=0:devel/p5-File-Slurp \
		p5-IPC-Run3>=0.036:devel/p5-IPC-Run3 \
		p5-List-MoreUtils>=0:lang/p5-List-MoreUtils \
		p5-Makefile-DOM>=0.005:textproc/p5-Makefile-DOM

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
