# Created by: Philippe Casidy <pcasidy@casidy.com>
# $FreeBSD$

PORTNAME=	whatpix
PORTVERSION=	1.2
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	http://whatpix.sourceforge.net/download/

MAINTAINER=	pcasidy@casidy.com
COMMENT=	Perl console application which finds, moves, or deletes duplicate files

RUN_DEPENDS=	p5-Digest-SHA1>=0:${PORTSDIR}/security/p5-Digest-SHA1

NO_BUILD=	yes
PLIST_FILES=	bin/whatpix
USES=		perl5 shebangfix
USE_PERL5=	run
SHEBANG_FILES=	whatpix

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/whatpix ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
