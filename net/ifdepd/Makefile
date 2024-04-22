PORTNAME=	ifdepd
PORTVERSION=	20110412
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://alex.bmg.gv.at/programs/

MAINTAINER=	alex@hugo.bmg.gv.at
COMMENT=	Interface Dependency daemon

USE_RC_SUBR=	${PORTNAME}

PLIST_FILES=	bin/ifdepd \
		share/man/man8/ifdepd.8.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ifdepd ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/ifdepd.8 ${STAGEDIR}${PREFIX}/share/man/man8

.include <bsd.port.mk>
