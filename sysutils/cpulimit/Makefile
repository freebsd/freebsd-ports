PORTNAME=	cpulimit
PORTVERSION=	2.2
CATEGORIES=	sysutils
MASTER_SITES=	SF/limitcpu/limitcpu/

MAINTAINER=	jessefrgsmith@yahoo.ca
COMMENT=	Limit the CPU usage of a process

LICENSE=	GPLv2

CFLAGS+=	-lkvm -Wall -O2

PLIST_FILES=	bin/cpulimit \
				man/man1/cpulimit.1.gz

post-patch:
	@${REINPLACE_CMD} -e 's|share/||g' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|gcc|${CC}|g' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cpulimit ${STAGEDIR}${PREFIX}/bin/cpulimit
	${INSTALL_MAN} ${WRKSRC}/cpulimit.1 ${STAGEDIR}${MANPREFIX}/man/man1/cpulimit.1

.include <bsd.port.mk>
