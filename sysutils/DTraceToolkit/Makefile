# Created by: Steven Kreuzer <steven@exit2shell.com>
# $FreeBSD$

PORTNAME=	DTraceToolkit
PORTVERSION=	0.99
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.brendangregg.com/DTraceToolkit/

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Collection of useful scripts for DTrace

USES=		shebangfix
sh_OLD_CMD=	/usr/bin/sh
sh_CMD=		${SH}
SHEBANG_LANG+=	sh

SHEBANG_FILES=	hotkernel procsystime opensnoop Apps/shellsnoop
NO_BUILD=	YES

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC}; ${TAR} --exclude '*.orig' -cf - . ) | \
		(cd ${STAGEDIR}${DATADIR}/; ${TAR} xvf -)
	${LN} -fs ${DATADIR}/hotkernel ${STAGEDIR}${PREFIX}/bin/hotkernel
	${LN} -fs ${DATADIR}/procsystime ${STAGEDIR}${PREFIX}/bin/procsystime
	${LN} -fs ${DATADIR}/opensnoop ${STAGEDIR}${PREFIX}/bin/opensnoop
	${LN} -fs ${DATADIR}/Apps/shellsnoop ${STAGEDIR}${PREFIX}/bin/shellsnoop

.include <bsd.port.mk>
