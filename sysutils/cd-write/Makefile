# New ports collection makefile for:    cd-write
# Date created:         1 May 1997
# Whom:                 jmz
#
# $FreeBSD$
#

PORTNAME=	cd-write
PORTVERSION=	1.4.1
CATEGORIES=	sysutils
MASTER_SITES=	http://people.FreeBSD.org/~jmz/

MAINTAINER=	jmz@FreeBSD.org

LIB_DEPENDS=	tixsam4182.1:${PORTSDIR}/x11-toolkits/tix

WRKSRC=		${WRKDIR}/cd-write

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 300000
BROKEN=		CAM
.endif

BROKEN=		"Missing TK header - see http://bento.freebsd.org/errorlogs/3-full/cd-write-1.4.1.log"

pre-build:
	@cd ${WRKSRC}; ${MV} Makefile Makefile~; \
		${SED} -e s:/usr/local:${PREFIX}:g <Makefile~ >Makefile;\
		${ECHO} all: cd-write >> Makefile
	@cd ${WRKSRC}/c++tk; ${MV} Makefile Makefile~; \
		${SED} -e s:/usr/local:${PREFIX}:g <Makefile~ >Makefile

post-install:
	@PREFIX=${PREFIX} ${SH} ${PKGDIR}/INSTALL ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
