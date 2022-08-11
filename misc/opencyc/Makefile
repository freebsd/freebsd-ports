PORTNAME=	opencyc
PORTVERSION=	0.7.0
PORTREVISION=	3
CATEGORIES=	misc linux
MASTER_SITES=	SF/${PORTNAME}/OldFiles
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	General knowledge base and commonsense reasoning engine

USES=		linux
USE_LINUX=	xorglibs
NO_BUILD=	yes

PLIST_SUB=	PORTVERSION="${PORTVERSION}"

post-extract:
	@cd ${WRKSRC}/doc && ${RM} '#migration.txt#' 'package-list.~1~' '.#faq' '.#migration.txt'

pre-patch:
	@${BRANDELF} -t Linux ${WRKSRC}/run/bin/latest.bin

do-install:
	@${CP} -PRpf ${WRKSRC} ${STAGEDIR}${PREFIX}

.include <bsd.port.mk>
