# Created by: Patrick Powell <papowell@astart.com>
# $FreeBSD$

PORTNAME=	pic2fig
PORTVERSION=	1.4
PORTREVISION=	2
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	utilities
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Pic format to fig format converter

WRKSRC=		${WRKDIR}/${PORTNAME}
CFLAGS+=	-Wno-return-type
MAN1=		pic2fig.1
PLIST_FILES=	bin/pic2fig

NO_STAGE=	yes
do-install:
	${INSTALL_PROGRAM} -m 755 ${WRKSRC}/pic2fig ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/pic2fig.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
