# New ports collection makefile for:    cd-write
# Date created:         1 May 1997
# Whom:                 jmz
#
# $FreeBSD$
#

PORTNAME=	cd-write
PORTVERSION=	1.4.2
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	jmz

MAINTAINER=	jmz@FreeBSD.org
COMMENT=	A X11 based CD-burner

LIB_DEPENDS=	tixsam8184.1:${PORTSDIR}/x11-toolkits/tix
USE_PERL5_BUILD=	yes

WRKSRC=		${WRKDIR}/cd-write

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 300000
IGNORE=		"FreeBSD 3.X or greater is required to support this port"
.endif

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

.include <bsd.port.post.mk>
