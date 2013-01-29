# $FreeBSD$

PORTNAME=	revealrk
PORTVERSION=	1.0.1
CATEGORIES=	security
MASTER_SITES=	SF/${PORTNAME}/
EXTRACT_SUFX=	.tgz

MAINTAINER=	fbsd-ports@opsec.eu
COMMENT=	Search hidden procs/rootkits from cron with low false positive rate

LICENSE=	GPLv3

PLIST_FILES=	bin/revealrk
MAN1=		revealrk.1

MANCOMPRESSED=	yes
NO_MANCOMPRESS=	yes

USE_SCONS=	yes
.if !empty(PREFIX)
SCONS_ARGS=	--prefix=${PREFIX}
.else
SCONS_ARGS=	--prefix=${LOCALBASE}
.endif

.include <bsd.port.mk>
