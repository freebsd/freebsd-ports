# New ports collection makefile for:	chrootuid
# Date created:				12 Dec 1999
# Whom:					truckman
#
# $FreeBSD$
#

PORTNAME=	chrootuid
PORTVERSION=	1.2
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.porcupine.org/pub/security/ \
		ftp://ftp.cerias.purdue.edu/pub/tools/unix/sysutils/chrootuid/
DISTNAME=	${PORTNAME}${PORTVERSION}
EXTRACT_SUFX=	.shar.Z

MAINTAINER=	truckman@FreeBSD.org

BUILD_DEPENDS=	gunshar:${PORTSDIR}/archivers/gshar+gunshar

EXTRACT_CMD=	uncompress
EXTRACT_BEFORE_ARGS=	-c
EXTRACT_AFTER_ARGS=	| gunshar -d ${WRKDIR}
NO_WRKSUBDIR=	yes

MAN8=		chrootuid.8

do-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/chrootuid
	${INSTALL_MAN} ${WRKSRC}/README ${PREFIX}/share/doc/chrootuid
.endif
	${INSTALL_PROGRAM} ${WRKSRC}/chrootuid ${PREFIX}/sbin/chrootuid
	${CP} ${WRKSRC}/chrootuid.1 ${WRKSRC}/chrootuid.8
	${INSTALL_MAN} ${WRKSRC}/${MAN8} ${PREFIX}/man/man8

.include <bsd.port.mk>
