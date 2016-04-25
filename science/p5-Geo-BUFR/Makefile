# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	Geo-BUFR
PORTVERSION=	1.33
CATEGORIES=	science perl5 geography
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:PSANNES
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension for handling of WMO BUFR files

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENCE

USES=		perl5 shebangfix
SHEBANG_FILES=	*.pl
USE_PERL5=	configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Geo/BUFR/BUFR.so

.include <bsd.port.mk>
