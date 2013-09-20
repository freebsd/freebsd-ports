# Created by: David O'Brien <obrien@NUXI.com>
# $FreeBSD$

PORTNAME=	44bsd-rdist
PORTVERSION=	20001111
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	cy

MAINTAINER=	cy@FreeBSD.org
COMMENT=	The traditional 4.4BSD rdist

USE_BZIP2=	yes

NO_WRKSUBDIR=	yes
MAN1=		44bsd-rdist.1
PLIST_FILES=	bin/44bsd-rdist

NO_STAGE=	yes
post-extract:
	cd ${WRKSRC} ; co RCS/*,v

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rdist ${PREFIX}/bin/44bsd-rdist
	${INSTALL_MAN} ${WRKSRC}/rdist.1 ${PREFIX}/man/man1/44bsd-rdist.1

tarup:
	-cd ${WRKSRC} ; ${RM} *
	cd ${WRKSRC} ; ${TAR} cvyf /tmp/${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX} .

.include <bsd.port.mk>
