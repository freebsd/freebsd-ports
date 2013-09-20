# Created by: nectar@FreeBSD.org
# $FreeBSD$

PORTNAME=	smurflog
PORTVERSION=	2.1
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	PACKETSTORM/UNIX/loggers

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A program to assist logging of smurf attacks

USE_CSTD=	gnu89
GNU_CONFIGURE=	yes

PORTDOCS=	README
PLIST_FILES=	sbin/smurflog

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e \
		's|^CFLAGS=|#CFLAGS=|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		'/strip/d' ${WRKSRC}/Makefile.in

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} smurflog ${PREFIX}/sbin)
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} README ${DOCSDIR})
.endif

.include <bsd.port.mk>
