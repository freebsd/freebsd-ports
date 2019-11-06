# Created by: Andriy Gapon <avg@icyb.net.ua>
# $FreeBSD$

PORTNAME=	i2c-tools
PORTVERSION=	3.1.1
CATEGORIES=	sysutils
MASTER_SITES=	http://dl.lm-sensors.org/i2c-tools/releases/

MAINTAINER=	avg@FreeBSD.org
COMMENT=	Heterogeneous set of I2C tools

BROKEN=		unfetchable

LICENSE=	GPLv2

NO_BUILD=	yes
USES=		perl5 shebangfix tar:bzip2
USE_PERL5=	run

PLIST_FILES=	man/man1/decode-dimms.1.gz sbin/decode-dimms
SHEBANG_FILES=	eeprom/decode-dimms

do-install:
	${INSTALL_MAN} ${WRKSRC}/eeprom/decode-dimms.1 \
		${STAGEDIR}${PREFIX}/man/man1/
	${INSTALL_SCRIPT} ${WRKSRC}/eeprom/decode-dimms \
		${STAGEDIR}${PREFIX}/sbin

.include <bsd.port.mk>
