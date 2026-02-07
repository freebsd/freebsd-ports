PORTNAME=	i2c-tools
DISTVERSION=	4.3
CATEGORIES=	sysutils
MASTER_SITES=	https://mirrors.edge.kernel.org/pub/software/utils/i2c-tools/

MAINTAINER=	avg@FreeBSD.org
COMMENT=	Heterogeneous set of I2C tools
WWW=		https://i2c.wiki.kernel.org/index.php/I2C_Tools

LICENSE=	GPLv2

NO_BUILD=	yes
USES=		perl5 shebangfix tar:xz
USE_PERL5=	run

PLIST_FILES=	sbin/decode-dimms share/man/man1/decode-dimms.1.gz
SHEBANG_FILES=	eeprom/decode-dimms

do-install:
	${INSTALL_MAN} ${WRKSRC}/eeprom/decode-dimms.1 \
		${STAGEDIR}${PREFIX}/share/man/man1/
	${INSTALL_SCRIPT} ${WRKSRC}/eeprom/decode-dimms \
		${STAGEDIR}${PREFIX}/sbin

.include <bsd.port.mk>
