# Created by: Jeffrey Goldberg <jeffrey@goldmark.org>
# $FreeBSD$

PORTNAME=	Lchown
PORTVERSION=	1.01
PORTREVISION=	1
CATEGORIES=	sysutils perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:NCLEATON
PKGNAMEPREFIX=	p5-

MAINTAINER=	jeffrey@goldmark.org
COMMENT=	Perl5 module providing access to lchown(2)

USES=		perl5
USE_PERL5=	modbuild

post-install:
	${STRIP_CMD} ${STAGEDIR}${SITE_PERL}/${PERL_ARCH}/auto/Lchown/Lchown.so

.include <bsd.port.mk>
