# Created by: Vladimir Laskov <samflanker@gmail.com>
# $FreeBSD$

PORTNAME=	megacli
PORTVERSION=	8.05.06
CATEGORIES=	sysutils
MASTER_SITES=	http://www.lsi.com/downloads/Public/MegaRAID%20Common%20Files/ \
		CRITICAL
DISTNAME=	${PORTVERSION}_MegaCLI

MAINTAINER=	samflanker@gmail.com
COMMENT=	SAS MegaRAID FreeBSD MegaCLI

RESTRICTED=	Source recipient must acknowledge license. Reproduction or redistribution prohibited. See http://www.lsi.com/lookup/License.aspx

FETCH_BEFORE_ARGS=	-o ${DISTDIR}/${DISTFILES}

ONLY_FOR_ARCHS=	i386 amd64

USE_ZIP=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	sbin/MegaCli

NO_STAGE=	yes
pre-fetch:
	@${FETCH_BINARY} -o /dev/null http://www.lsi.com/magic.axd?x=e&file=http%3A//www.lsi.com/downloads/Public/MegaRAID%2520Common%2520Files/${PORT_VERSION}_MegaCLI.zip

.include <bsd.port.pre.mk>
post-extract:
.if ${ARCH} == "i386"
	@cd ${WRKSRC}/MegaCli_FreeBSD && ${UNZIP_CMD} ${EXTRACT_BEFORE_ARGS} MegaCli.zip
.elif ${ARCH} == "amd64"
	@cd ${WRKSRC}/MegaCli_FreeBSD && ${UNZIP_CMD} ${EXTRACT_BEFORE_ARGS} MegaCli64.zip
.endif

do-install:
.if ${ARCH} == "i386"
		${INSTALL_PROGRAM} ${WRKSRC}/MegaCli_FreeBSD/MegaCli ${PREFIX}/sbin/MegaCli
.elif ${ARCH} == "amd64"
		${INSTALL_PROGRAM} ${WRKSRC}/MegaCli_FreeBSD/MegaCli64 ${PREFIX}/sbin/MegaCli
.endif
.include <bsd.port.post.mk>
