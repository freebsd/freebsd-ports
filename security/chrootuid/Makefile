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

LICENSE=	MIT # MIT-like actually
LICENSE_FILE=	${WRKSRC}/chrootuid_license

PLIST_FILES=	sbin/chrootuid man/man8/chrootuid.1.gz
PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/chrootuid ${STAGEDIR}${PREFIX}/sbin/
	${INSTALL_MAN} ${WRKSRC}/chrootuid.1 ${STAGEDIR}${PREFIX}/man/man8

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
