# Created by: sterling
# $FreeBSD$

PORTNAME=	pcpustat
PORTVERSION=	1.6
CATEGORIES=	sysutils
MASTER_SITES=	http://chipstips.com/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Per-CPU usage statistics

LICENSE=	OWL

USES=		tar:bzip2

PLIST_FILES=	bin/pcpustat \
		man/man1/pcpustat.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/man/man1/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1/

.include <bsd.port.mk>
