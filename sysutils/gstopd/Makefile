PORTNAME=	gstopd
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	LOCAL/mr

MAINTAINER=	mr@FreeBSD.org
COMMENT=	GEOM stop daemon

LICENSE=	BSD2CLAUSE

PLIST_FILES=	sbin/gstopd share/man/man8/gstopd.8.gz

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400091 || ( ${OSVERSION} >= 1302507 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=unused-but-set-variable
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gstopd ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/gstopd.8 ${STAGEDIR}${PREFIX}/share/man/man8

.include <bsd.port.mk>
