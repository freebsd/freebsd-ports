# New ports collection makefile for:	sjitter
# Date created:		2006-10-29
# Whom:			babak@farrokhi.net
#
# $FreeBSD$
#

PORTNAME=	sjitter
PORTVERSION=	0.14b
CATEGORIES=	net-mgmt net
MASTER_SITES=	http://www.alcasat.net/dev/sjitter/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A client/server jitter measurement utility

WRKSRC=		${WRKDIR}
USE_GMAKE=	yes

MAN1=		sjitter.1
MANCOMPRESSED=	yes

PLIST_FILES=	sbin/sjitters sbin/sjitterc

post-patch:
	@${REINPLACE_CMD} -e "s,^CC,#CC,g ; \
	    s,^LDFLAGS,LDFLAGS+,g ; \
	    s,^CFLAGS,CFLAGS+,g" ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sjitters ${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/sjitterc ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/sjitter.1.gz ${PREFIX}/man/man1

.include <bsd.port.mk>
