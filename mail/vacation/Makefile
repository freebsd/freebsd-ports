# Created by: Adam McDougall <mcdouga9@egr.msu.edu>
# $FreeBSD$

PORTNAME=	vacation
PORTVERSION=	3.3.3
CATEGORIES=	mail
MASTER_SITES=	DEBIAN
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	cy@FreeBSD.org
COMMENT=	Email autoresponder, similar to vacation from sendmail

PORTSCOUT=	ignore:1

USES=		bdb

CFLAGS+=	-L${LOCALBASE}/lib

WRKSRC=		${WRKDIR}/work

PLIST_FILES=	bin/vacation man/man1/vacation.1.gz

post-patch:
	@${REINPLACE_CMD} -e 's|-ldb|-l${BDB_LIB_NAME}|g' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|CFLAGS=|CFLAGS+=|g' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|-O2||g' \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vacation ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/vacation.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
