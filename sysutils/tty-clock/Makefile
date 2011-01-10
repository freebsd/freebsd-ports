# Ports collection makefile for:	tty-clock
# Date created:				15 July 2010
# Whom:					Eric Freeman <freebsdports@chillibear.com>
#
# $FreeBSD$
#

PORTNAME=		tty-clock
PORTVERSION=		2.0.0
CATEGORIES=		sysutils
MASTER_SITES=		http://github.com/xorg62/${PORTNAME}/tarball/
DISTNAME=		a82fd71
EXTRACT_SUFX=		# none

MAINTAINER=		freebsdports@chillibear.com
COMMENT=		Terminal based clock

FETCH_ARGS=		-pRr
WRKSRC=			"${WRKDIR}/xorg62-${PORTNAME}-${DISTNAME}"
PLIST_FILES=		bin/tty-clock

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local/|${PREFIX}/|' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|CFLAGS =|CFLAGS \+=|' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|LDFLAGS =|LDFLAGS \+=|' ${WRKSRC}/Makefile

do-build:
	cd ${WRKSRC} && ${MAKE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tty-clock ${PREFIX}/bin

.include <bsd.port.pre.mk>

.if ${OSVERSION} > 900007
BROKEN=	Core dumps on FreeBSD 9+
.endif

.include <bsd.port.post.mk>
