# New ports collection makefile for:    cd-write
# Date created:         1 May 1997
# Whom:                 jmz
#
# $FreeBSD$
#

PORTNAME=	cd-write
PORTVERSION=	1.4.2
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	jmz

MAINTAINER=	jmz@FreeBSD.org
COMMENT=	A X11 based CD-burner

LIB_DEPENDS=	tixsam8184.1:${PORTSDIR}/x11-toolkits/tix
USE_PERL5_BUILD=	yes

WRKSRC=		${WRKDIR}/cd-write

PLIST_FILES=	bin/cd-write

pre-build:
	@cd ${WRKSRC}; ${ECHO_CMD} all: cd-write >> Makefile
	@cd ${WRKSRC}/c++tk; ${MV} Makefile Makefile~; \
		${SED} -e s:/usr/local:${PREFIX}:g \
		-e s:/usr/X11R6:${X11BASE}:g <Makefile~ >Makefile
	@cd ${WRKSRC}; ${MV} Makefile Makefile~; \
		${SED} -e s:/usr/local:${PREFIX}:g \
		-e s:/usr/X11R6:${X11BASE}:g <Makefile~ >Makefile

post-install:
	@PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
