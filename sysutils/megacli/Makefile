# Created by: Vladimir Laskov <samflanker@gmail.com>
# $FreeBSD$

PORTNAME=	megacli
DISTVERSION=	8-07-14
CATEGORIES=	sysutils
MASTER_SITES=	https://docs.broadcom.com/docs-and-downloads/raid-controllers/raid-controllers-common-files/\
		http://ftp.wsisiz.edu.pl/pub/pc/drivers/lsi/
DISTNAME=	${DISTVERSION}_MegaCLI

MAINTAINER=	samflanker@gmail.com
COMMENT=	SAS MegaRAID FreeBSD MegaCLI

LICENSE=	megacli
LICENSE_NAME=	BROADCOM
LICENSE_TEXT=	Source recipient must acknowledge license.\
		Reproduction or redistribution prohibited.\
		See https://www.broadcom.com/cs/Satellite?pagename=AVG2/Utilities/EulaMsg
LICENSE_PERMS=	no-dist-mirror no-dist-sell no-pkg-mirror no-pkg-sell auto-accept

USES=		zip

ONLY_FOR_ARCHS=	i386 amd64

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	sbin/MegaCli

MEGACLI_ARCH=	MegaCli${ARCH:S/i386//:S/amd64/64/}

post-extract:
	@${MV} ${WRKSRC}/FreeBSD/MegaCLI.zip ${WRKSRC}/FreeBSD/MegaCli.zip
	@${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${WRKSRC}/FreeBSD/${MEGACLI_ARCH}.zip -d ${WRKSRC}/FreeBSD

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/FreeBSD/${MEGACLI_ARCH} ${STAGEDIR}${PREFIX}/sbin/MegaCli

.include <bsd.port.mk>
