# New ports collection makefile for:    cd-write
# Date created:         1 May 1997
# Whom:                 jmz
#
# $FreeBSD$
#

PORTNAME=	cd-write
PORTVERSION=	1.4.1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	jmz

MAINTAINER=	jmz@FreeBSD.org

LIB_DEPENDS=	tixsam4182.1:${PORTSDIR}/x11-toolkits/tix
USE_PERL5_BUILD=	yes

WRKSRC=		${WRKDIR}/cd-write

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 300000
BROKEN=		CAM
.endif

pre-build:
	@cd ${WRKSRC}; ${MV} Makefile Makefile~; \
		${SED} -e s:/usr/local:${PREFIX}:g -e s/CFL/CXXFL/ <Makefile~ >Makefile;\
		${ECHO_CMD} all: cd-write >> Makefile
	@cd ${WRKSRC}/c++tk; ${MV} Makefile Makefile~; \
		${SED} -e s:/usr/local:${PREFIX}:g <Makefile~ >Makefile

post-install:
	@PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
