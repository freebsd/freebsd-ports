# New ports collection makefile for:	rkive
# Date created:		03 Jul 1995
# Whom:			torsten@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	rkive
PORTVERSION=	3.1
CATEGORIES=	news
MASTER_SITES=	ftp://ftp.vmunix.org/pub/misc/rkive/
DISTNAME=	${PORTNAME}${PORTVERSION}
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A USENET newsgroup archiver

NO_CDROM=	"Don't make money from it"
MAN1=		rkive.1 article.1 ckconfig.1
MAN5=		rkive.5
MANCOMPRESSED=	yes
USE_REINPLACE=	yes

pre-patch:
	@${CP} ${WRKSRC}/Makefile.dst ${WRKSRC}/Makefile
	@${CP} ${WRKSRC}/rkive.h.dst ${WRKSRC}/rkive.h

post-patch:
	${REINPLACE_CMD} -e "s,^int fprintf();,," ${WRKSRC}/header.c \
		${WRKSRC}/rkive.h  ${WRKSRC}/version.c ${WRKSRC}/efopen.c
	${REINPLACE_CMD} -e "s,^int sscanf();,," ${WRKSRC}/setup.c \
		${WRKSRC}/record_arc.c
	${REINPLACE_CMD} -e "s,int mkdir();,," ${WRKSRC}/makedir.c
	${REINPLACE_CMD} -e "s,int chmod();,," ${WRKSRC}/rkive.c

.include <bsd.port.mk>
