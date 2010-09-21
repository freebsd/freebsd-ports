# New ports collection makefile for:	p5-arclog
# Date created:				2008/05/18
# Whom:					chinsan
#
# $FreeBSD$
#

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
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes
MAN1=		arclog.1

PLIST_FILES=	bin/arclog \
		%%SITE_PERL%%/%%PERL_ARCH%%/auto/arclog/.packlist
PLIST_DIRS=	%%SITE_PERL%%/%%PERL_ARCH%%/auto/arclog

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500903
RUN_DEPENDS+=	p5-IO-Compress>=2.017:${PORTSDIR}/archivers/p5-IO-Compress
.endif

.include <bsd.port.post.mk>
