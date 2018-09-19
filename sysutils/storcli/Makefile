# $FreeBSD$

PORTNAME=	storcli
DISTVERSION=	7.709
CATEGORIES=	sysutils
MASTER_SITES=	https://docs.broadcom.com/docs-and-downloads/raid-controllers/raid-controllers-common-files/
DISTNAME=	007.0709.0000.0000_Unified_StorCLI

MAINTAINER=	takefu@airport.fm
COMMENT=	SAS MegaRAID FreeBSD StorCLI

LICENSE=	storcli
LICENSE_NAME=	BROADCOM
LICENSE_TEXT=	Source recipient must acknowledge license.\
		Reproduction or redistribution prohibited.\
		See https://www.broadcom.com/cs/Satellite?pagename=AVG2/Utilities/EulaMsg
LICENSE_PERMS=	no-dist-mirror no-dist-sell no-pkg-mirror no-pkg-sell auto-accept

ONLY_FOR_ARCHS=	amd64 i386

USES=		zip

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	sbin/storcli
PKGMESSAGE=	${WRKDIR}/pkg-message
BINSRC=		${WRKSRC}/Unified_storcli_all_os/FreeBSD

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
DOWNLOAD_URL=	https://docs.broadcom.com/docs-and-downloads/raid-controllers/raid-controllers-common-files/${DISTNAME}${EXTRACT_SUFX}

IGNORE?=	You must manually fetch the distribution file\
	(${DISTNAME}${EXTRACT_SUFX}) from ${DOWNLOAD_URL},\
	place it in ${DISTDIR} and then run make again
.endif

post-extract:
	@${TAR} xf ${WRKSRC}/Unified_storcli_all_os${EXTRACT_SUFX} -C${WRKSRC}
	@${TAR} xf ${BINSRC}/storcli${ARCH:S/i386//:S/amd64/64/}.tar -C${WRKSRC}
	@${REINPLACE_CMD} 's#\(StorCli\).*StorCli64#\1#'\
		${BINSRC}/FreeBSD_readme.txt
	@${FMT} 75 79 ${BINSRC}/FreeBSD_readme.txt > ${WRKDIR}/pkg-message

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/storcli${ARCH:S/i386//:S/amd64/64/}\
		${STAGEDIR}${PREFIX}/sbin/storcli

.include <bsd.port.post.mk>
