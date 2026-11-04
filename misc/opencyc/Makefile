PORTNAME=	opencyc
DISTVERSION=	0.7.0
PORTREVISION=	4
CATEGORIES=	misc linux
MASTER_SITES=	SF/${PORTNAME}/OldFiles

MAINTAINER=	ports@FreeBSD.org
COMMENT=	General knowledge base and commonsense reasoning engine
WWW=		http://www.opencyc.org

DEPRECATED=	Upstream abandoned in 2017
EXPIRATION_DATE=	2026-12-04

USES=		linux tar:tgz
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
