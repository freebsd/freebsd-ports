PORTNAME=	radeontool
PORTVERSION=	1.5
CATEGORIES=	sysutils
MASTER_SITES=	http://fdd.com/software/radeon/

MAINTAINER=	takawata@jp.freebsd.org
COMMENT=	ATI Radeon video card controlling tool useful for laptops

do-install:
	${INSTALL_PROGRAM} -C -s ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
