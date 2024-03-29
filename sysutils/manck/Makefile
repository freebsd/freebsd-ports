PORTNAME=	manck
PORTVERSION=	1.2
PORTREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	http://wolfram.schneider.org/src/

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Manual page consistency checker

RUN_DEPENDS=	p5-Perl4-CoreLibs>=0:devel/p5-Perl4-CoreLibs

USES=		perl5 shebangfix uidfix
USE_PERL5=	run
SHEBANG_FILES=	manck.pl

MAKE_ARGS=	MANDIR=${PREFIX}/share/man/man

.include <bsd.port.mk>
