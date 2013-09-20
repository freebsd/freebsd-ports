# Created by: Andriy Gapon <avg@icyb.net.ua>
# $FreeBSD$

PORTNAME=	i2c-tools
PORTVERSION=	3.1.0
CATEGORIES=	sysutils
MASTER_SITES=	http://dl.lm-sensors.org/i2c-tools/releases/

MAINTAINER=	avg@icyb.net.ua
COMMENT=	A heterogeneous set of I2C tools

USE_BZIP2=	yes
NO_BUILD=	yes
USES=		perl5
USE_PERL5=	run

PLIST_FILES=	sbin/decode-dimms

NO_STAGE=	yes
do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/eeprom/decode-dimms ${PREFIX}/sbin/decode-dimms

.include <bsd.port.mk>
