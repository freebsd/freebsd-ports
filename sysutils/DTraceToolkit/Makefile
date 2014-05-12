# Created by: Steven Kreuzer <steven@exit2shell.com>
# $FreeBSD$

PORTNAME=	DTraceToolkit
PORTVERSION=	0.99
CATEGORIES=	sysutils
MASTER_SITES=	http://www.brendangregg.com/DTraceToolkit/

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Collection of useful scripts for DTrace

USES=	shebangfix
sh_OLD_CMD=	/usr/bin/sh
sh_CMD=	${SH}
SHEBANG_LANG+=	sh

SHEBANG_FILES=	hotkernel procsystime
NO_BUILD=	YES

.include <bsd.port.pre.mk>

.if ${OSVERSION} <= 701000
IGNORE=	needs to have dtrace enabled kernel
.endif

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC}; ${TAR} cf - . ) | \
		(cd ${STAGEDIR}${DATADIR}/; ${TAR} xvf -)

post-install:
	${LN} -fs ${DATADIR}/hotkernel ${STAGEDIR}${PREFIX}/bin/hotkernel
	${LN} -fs ${DATADIR}/procsystime ${STAGEDIR}${PREFIX}/bin/procsystime
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
