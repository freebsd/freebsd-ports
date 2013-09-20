# Created by: truckman
# $FreeBSD$

PORTNAME=	chrootuid
PORTVERSION=	1.3
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.porcupine.org/pub/security/ \
		ftp://ftp.cerias.purdue.edu/pub/tools/unix/sysutils/chrootuid/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple wrapper that combines chroot(8) and su(1) into  one  program

MAN8=		chrootuid.8

NO_STAGE=	yes
do-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/chrootuid_license ${DOCSDIR}
.endif
	${INSTALL_PROGRAM} ${WRKSRC}/chrootuid ${PREFIX}/sbin/
	${INSTALL_MAN} ${WRKSRC}/chrootuid.1 ${PREFIX}/man/man8/${MAN8}

.include <bsd.port.mk>
