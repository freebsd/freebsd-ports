# New ports collection makefile for:	p5-reslog
# Date created:				2008/05/18
# Whom:					chinsan
#
# $FreeBSD$
#

PORTNAME=	reslog
PORTVERSION=	3.16
CATEGORIES=	sysutils perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	Locale/IMACAT
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Reverse-resolve IP in Apache log files

BUILD_DEPENDS=	p5-Compress-Bzip2>=0:${PORTSDIR}/archivers/p5-Compress-Bzip2 \
		p5-Compress-Zlib>=0:${PORTSDIR}/archivers/p5-Compress-Zlib \
		p5-File-MMagic>=0:${PORTSDIR}/devel/p5-File-MMagic \
		p5-Term-ReadKey>=0:${PORTSDIR}/devel/p5-Term-ReadKey \
		p5-ExtUtils-MakeMaker>=0:${PORTSDIR}/devel/p5-ExtUtils-MakeMaker
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes
MAN1=		reslog.1

PLIST_FILES=	bin/reslog \
		%%SITE_PERL%%/%%PERL_ARCH%%/auto/reslog/.packlist
PLIST_DIRS=	%%SITE_PERL%%/%%PERL_ARCH%%/auto/reslog

.include <bsd.port.mk>
