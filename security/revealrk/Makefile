# $FreeBSD$

PORTNAME=	revealrk
PORTVERSION=	1.1.2
CATEGORIES=	security
MASTER_SITES=	SF/${PORTNAME}/

MAINTAINER=	pi@FreeBSD.org
COMMENT=	Search hidden procs/rootkits from cron with low false positive rate

LICENSE=	GPLv3

PLIST_FILES=	bin/revealrk man/man1/revealrk.1.gz

USES=		scons tar:tgz

.if !empty(PREFIX)
MAKE_ARGS+=    --prefix=${STAGEDIR}${PREFIX}
.else
MAKE_ARGS+=    --prefix=${STAGEDIR}${LOCALBASE}
.endif

.include <bsd.port.mk>
