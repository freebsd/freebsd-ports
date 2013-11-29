# Created by: Vladimir Laskov <samflanker@gmail.com>
# $FreeBSD$

PORTNAME=	megacli
PORTVERSION=	8.07.07
CATEGORIES=	sysutils
MASTER_SITES=	http://www.lsi.com/downloads/Public/MegaRAID%20Common%20Files/${DISTNAME}${EXTRACT_SUFX}?source=1&
DISTNAME=	${PORTVERSION}_MegaCLI
EXTRACT_SUFX=	.zip

MAINTAINER=	samflanker@gmail.com
COMMENT=	SAS MegaRAID FreeBSD MegaCLI

RESTRICTED=	Source recipient must acknowledge license. Reproduction or redistribution prohibited. See http://www.lsi.com/lookup/License.aspx

FETCH_BEFORE_ARGS=	-o ${DISTDIR}/${DISTFILES}

ONLY_FOR_ARCHS=	i386 amd64

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	sbin/MegaCli

MEGACLI_ARCH=	MegaCli${ARCH:S/i386//:S/amd64/64/}

post-extract:
	@${MV} ${WRKSRC}/freebsd/MegaCLI.zip ${WRKSRC}/freebsd/MegaCli.zip
	@${TAR} ${EXTRACT_BEFORE_ARGS} ${WRKSRC}/freebsd/${MEGACLI_ARCH}.zip -C${WRKSRC}/freebsd

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/freebsd/${MEGACLI_ARCH} ${STAGEDIR}${PREFIX}/sbin/MegaCli

.include <bsd.port.mk>
