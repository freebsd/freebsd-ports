# New ports collection makefile for:	pwcbsd
# Date created:				17 Feb 2006
# Whom:					Raaf <freebsd@luna.afraid.org>
#
# $FreeBSD$
#

PORTNAME=	pwcbsd
PORTVERSION=	1.2
CATEGORIES=	multimedia sysutils
MASTER_SITES=	http://raaf.atspace.org/

MAINTAINER=	freebsd@luna.afraid.org
COMMENT=	The Linux pwc webcam driver ported to FreeBSD

MAN4=		pwc.4

WRKSRC=		${WRKDIR}/${PORTNAME}
NO_PACKAGE=	should be recompiled for a particular FreeBSD kernel

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 504000
IGNORE=		requires FreeBSD 5.4 or superior
.endif

.if !exists(/usr/src/sys/Makefile)
IGNORE=		requires kernel source files
.endif

.if !defined(WITHOUT_PROGRAMS)
ALL_TARGET=	all pwcview
PROGRAMS=	pwcview
MAN1=		pwcview.1
USE_SDL=	sdl
PLIST_SUB+=	PROGRAMS=""
.else
PLIST_SUB+=	PROGRAMS="@comment "
.endif

pre-everything::
.if !defined(WITHOUT_PROGRAMS)
	@${ECHO_MSG} "=================================================="
	@${ECHO_MSG} "You may specify the following on the command line:"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "WITHOUT_PROGRAMS=yes	to only build the driver "
	@${ECHO_MSG} "=================================================="
.endif

post-patch:
.if !defined(WITHOUT_PROGRAMS)
	@${REINPLACE_CMD} -e 's|sdl11-config|${SDL_CONFIG}|g' ${WRKSRC}/Makefile
.endif

post-install:
	${MKDIR} ${PREFIX}/include/linux
	${INSTALL_DATA} ${WRKSRC}/videodev.h ${PREFIX}/include/linux
	${INSTALL_MAN} ${MAN4:S|^|${WRKSRC}/|} ${PREFIX}/man/man4
.if !defined(WITHOUT_PROGRAMS)
	${INSTALL_PROGRAM} ${PROGRAMS:S|^|${WRKSRC}/|} ${PREFIX}/bin
	${INSTALL_MAN} ${MAN1:S|^|${WRKSRC}/|} ${PREFIX}/man/man1
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
