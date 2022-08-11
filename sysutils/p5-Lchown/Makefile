PORTNAME=	Lchown
PORTVERSION=	1.01
PORTREVISION=	2
CATEGORIES=	sysutils perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:NCLEATON
PKGNAMEPREFIX=	p5-

MAINTAINER=	jeffrey@goldmark.org
COMMENT=	Perl5 module providing access to lchown(2)

USES=		perl5
USE_PERL5=	modbuild

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Lchown/Lchown.so

.include <bsd.port.mk>
