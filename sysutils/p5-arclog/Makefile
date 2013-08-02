# Created by: chinsan
# $FreeBSD$

PORTNAME=	arclog
PORTVERSION=	3.04
PORTREVISION=	2
CATEGORIES=	sysutils perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	Locale/IMACAT
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Archive the log files monthly

RUN_DEPENDS=	p5-TimeDate>=0:${PORTSDIR}/devel/p5-TimeDate \
		p5-Compress-Bzip2>=0:${PORTSDIR}/archivers/p5-Compress-Bzip2 \
		p5-File-MMagic>=0:${PORTSDIR}/devel/p5-File-MMagic \
		p5-Term-ReadKey>=0:${PORTSDIR}/devel/p5-Term-ReadKey
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure
MAN1=		arclog.1

PLIST_FILES=	bin/arclog \
		%%SITE_PERL%%/%%PERL_ARCH%%/auto/arclog/.packlist
PLIST_DIRS=	%%SITE_PERL%%/%%PERL_ARCH%%/auto/arclog

.include <bsd.port.mk>
