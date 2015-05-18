# Created by: Kris Moore <kmoore@FreeBSD.org>
# $FreeBSD$

PORTNAME=	life-preserver
PORTVERSION=	1431457302
CATEGORIES=	sysutils
MASTER_SITES=	http://www.pcbsd.org/~kris/software/ \
		ftp://ftp.pcbsd.org/pub/software/

MAINTAINER=	kmoore@FreeBSD.org
COMMENT=	PC-BSD Life Preserver Utility

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${LOCALBASE}/share/pcbsd/scripts/functions.sh:${PORTSDIR}/sysutils/pcbsd-libsh \
		stunnel:${PORTSDIR}/security/stunnel

WRKSRC=		${WRKDIR}/lpreserver
USES=		pkgconfig tar:xz
NO_BUILD=	yes
MAKE_ARGS=	PREFIX=${STAGEDIR}${PREFIX}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 1000000
IGNORE=		requires FreeBSD 10 or later
.endif

.include <bsd.port.post.mk>
