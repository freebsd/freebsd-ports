PORTNAME=	pcpustat
PORTVERSION=	1.6
CATEGORIES=	sysutils
MASTER_SITES=	https://bitbucket.org/sterlingcamden/pcpustat/get/
DISTNAME=	${PORTVERSION}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Per-CPU usage statistics

LICENSE=	OWL
LICENSE_FILE=	${WRKSRC}/license.txt

USES=		tar:bzip2
WRKSRC=		${WRKDIR}/sterlingcamden-pcpustat-2b8712536989

PLIST_FILES=	bin/pcpustat \
		man/man1/pcpustat.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/man/man1/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1/

.include <bsd.port.mk>
