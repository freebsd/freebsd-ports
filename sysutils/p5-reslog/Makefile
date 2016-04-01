# Created by: chinsan
# $FreeBSD$

PORTNAME=	reslog
PORTVERSION=	3.16
PORTREVISION=	3
CATEGORIES=	sysutils perl5
MASTER_SITES=	CPAN/Locale/IMACAT
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Reverse-resolve IP in Apache log files

RUN_DEPENDS=	p5-Compress-Bzip2>=0:archivers/p5-Compress-Bzip2 \
		p5-File-MMagic>=0:devel/p5-File-MMagic \
		p5-Term-ReadKey>=0:devel/p5-Term-ReadKey
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
