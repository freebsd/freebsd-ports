# $FreeBSD$

PORTNAME=	storcli
PORTVERSION=	1.20.15
CATEGORIES=	sysutils
MASTER_SITES=	https://docs.broadcom.com/docs-and-downloads/raid-controllers/raid-controllers-common-files/
DISTNAME=	${PORTVERSION}_StorCLI

MAINTAINER=	takefu@airport.fm
COMMENT=	SAS MegaRAID FreeBSD StorCLI

LICENSE=	storcli
LICENSE_NAME=	BROADCOM
LICENSE_TEXT=	Source recipient must acknowledge license.\
		Reproduction or redistribution prohibited.\
		See https://www.broadcom.com/cs/Satellite?pagename=AVG2/Utilities/EulaMsg
LICENSE_PERMS=	no-dist-mirror no-dist-sell no-pkg-mirror no-pkg-sell auto-accept

USES=		zip

ONLY_FOR_ARCHS=	i386 amd64

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	sbin/storcli
PKGMESSAGE=	${WRKDIR}/pkg-message
BINSRC=		${WRKSRC}/storcli_All_OS/storcli_All_OS/FreeBSD

post-extract:
	@${TAR} xf ${BINSRC}/storcli${ARCH:S/i386//:S/amd64/64/}.tar -C${WRKSRC}
	@${REINPLACE_CMD} 's#\(StorCli\).*StorCli64#\1#'\
		${BINSRC}/FreeBSD_readme.txt
	@${FMT} 75 79 ${BINSRC}/FreeBSD_readme.txt > ${WRKSRC}/pkg-message

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/storcli${ARCH:S/i386//:S/amd64/64/}\
		${STAGEDIR}${PREFIX}/sbin/storcli

.include <bsd.port.mk>
