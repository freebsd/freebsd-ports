# New ports collection makefile for:    cd-write
# Version required:     1.4.1
# Date created:         1 May 1997
# Whom:                 jmz
#
# $Id: Makefile,v 1.12 1998/11/11 05:37:31 asami Exp $
#

DISTNAME=       cd-write-1.4.1
CATEGORIES=     sysutils
MASTER_SITES=   http://www.FreeBSD.ORG/~jmz/

MAINTAINER=     jmz@FreeBSD.org

LIB_DEPENDS=	tixsam4180.1:${PORTSDIR}/x11-toolkits/tix

WRKSRC=		${WRKDIR}/cd-write

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 300000
BROKEN=		CAM
.endif

pre-build:
	@cd ${WRKSRC}; ${MV} Makefile Makefile~; \
		${SED} -e s:/usr/local:${PREFIX}:g <Makefile~ >Makefile;\
		${ECHO} all: cd-write >> Makefile
	@cd ${WRKSRC}/c++tk; ${MV} Makefile Makefile~; \
		${SED} -e s:/usr/local:${PREFIX}:g <Makefile~ >Makefile

post-install:
	@PREFIX=${PREFIX} ${SH} ${PKGDIR}/INSTALL ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
