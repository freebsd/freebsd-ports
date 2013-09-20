# Created by: Adam McDougall <mcdouga9@egr.msu.edu>
# $FreeBSD$

PORTNAME=	vacation
PORTVERSION=	3.3.0
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_DEBIAN}
MASTER_SITE_SUBDIR=	pool/main/v/vacation/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	mcdouga9@egr.msu.edu
COMMENT=	A email autoresponder, similar to vacation from sendmail

USE_BDB=	yes
CFLAGS+=	-L${LOCALBASE}/lib

MAN1=		vacation.1

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PLIST_FILES=	bin/vacation

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|-ldb|-l${BDB_LIB_NAME}|g' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|CFLAGS=|CFLAGS+=|g' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|-O2||g' \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vacation ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/vacation.1 ${PREFIX}/man/man1/

.include <bsd.port.mk>
