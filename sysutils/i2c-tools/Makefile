# Created by: Andriy Gapon <avg@icyb.net.ua>
# $FreeBSD$

PORTNAME=	i2c-tools
PORTVERSION=	4.1
CATEGORIES=	sysutils
MASTER_SITES=	https://mirrors.edge.kernel.org/pub/software/utils/i2c-tools/

MAINTAINER=	avg@FreeBSD.org
COMMENT=	Heterogeneous set of I2C tools

LICENSE=	GPLv2

NO_BUILD=	yes
USES=		perl5 shebangfix tar:xz
USE_PERL5=	run

PLIST_FILES=	man/man1/decode-dimms.1.gz sbin/decode-dimms
SHEBANG_FILES=	eeprom/decode-dimms

do-install:
	${INSTALL_MAN} ${WRKSRC}/eeprom/decode-dimms.1 \
		${STAGEDIR}${PREFIX}/man/man1/
	${INSTALL_SCRIPT} ${WRKSRC}/eeprom/decode-dimms \
		${STAGEDIR}${PREFIX}/sbin

.include <bsd.port.mk>
