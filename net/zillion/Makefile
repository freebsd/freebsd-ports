PORTNAME=	zillion
PORTVERSION=	0.1
PORTREVISION=	12
CATEGORIES=	net gnustep
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}
DISTNAME=	${PORTNAME}-0_1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Distributed computing project

LICENSE=	BSDunclear
LICENSE_NAME=	Unclear BSD License
LICENSE_TEXT=	License of this software is declared as 'BSD license' in ZillionClientServer.[hm] \
		of the source archive. But it is not clear which versions of the BSD license (2, \
		3 or 4 clause) it is. There is also a reference to a LICENSE file which is \
		supposed to be included in the source archive, but it is in fact not included.
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		gnustep
USE_GNUSTEP=	back build

WRKSRC=		${WRKDIR}/${PORTNAME}

post-patch:
	${REINPLACE_CMD} -e 's|^CC=|# CC=|' ${WRKSRC}/GNUmakefile

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/GNUstep/System/Library/Bundles/simpleZillionJob.bundle/simpleZillionJob
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/GNUstep/System/Tools/zillion
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/GNUstep/System/Tools/zillionClient
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/GNUstep/System/Tools/zillionLoader

.include <bsd.port.mk>
