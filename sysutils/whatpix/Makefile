# Created by: Philippe Casidy <pcasidy@casidy.com>
# $FreeBSD$

PORTNAME=	whatpix
PORTVERSION=	1.2
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	http://whatpix.sourceforge.net/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl console application which finds, moves, or deletes duplicate files

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	p5-Digest-SHA1>=0:security/p5-Digest-SHA1

NO_ARCH=	yes
NO_BUILD=	yes
PLIST_FILES=	bin/whatpix
USES=		perl5 shebangfix
USE_PERL5=	run
SHEBANG_FILES=	whatpix

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/whatpix ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
