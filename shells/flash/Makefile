# New ports collection makefile for:	flash
# Version required:	0.9.1
# Date created:		11 Dec 1999
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

DISTNAME=	flash-0.9.1
CATEGORIES=	shells
MASTER_SITES=	ftp://ftp.netsoc.ucd.ie/pub/computing/flash/

MAINTAINER=	will@FreeBSD.org

.include <bsd.port.pre.mk>

# outdated version of ncurses in non-CURRENT
.if ${OSVERSION} < 400000
LIB_DEPENDS=	ncurses.4:${PORTSDIR}/devel/ncurses
.endif

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
MAKE_ENV=	prefix=${PREFIX}
WRKSRC=		${WRKDIR}/flash
MAN1=		flash.1

pre-configure:
.if ${OSVERSION} < 400000
MAKE_ENV+=	NCURSES=-DHAVE_NCURSES_NCURSES_H \
		NC_CFLAGS="-I${LOCALBASE}/include" \
		NC_LFLAGS="-L${LOCALBASE}/lib"
.endif

pre-build:
	@${RM} -rf ${WRKSRC}/modules/countdown ${WRKSRC}/modules/background

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/flash ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/lib/flash/flashdocs/
.for DOC in checkflash system.bg.Netsoc.3 system.bg.Netsoc.4 system.flashlogin \
	    system.maillogin system.module system.module.9798 system.rc system.rc.mailshell
	@${INSTALL_DATA} ${WRKSRC}/orcasetup/${DOC} ${PREFIX}/lib/flash/
.endfor
.for PROG in background countdown
	@${INSTALL_PROGRAM} ${WRKSRC}/modules/${PROG} ${PREFIX}/lib/flash/
.endfor
.for SCRIPT in mailshell system.menu system.menu.9798 system.menu.oldlast system.menu~ \
	       system.menu.old
	@${PERL} -pi -e "s:/usr/slocal:${PREFIX}:g" ${WRKSRC}/orcasetup/${SCRIPT}
	@${INSTALL_SCRIPT} ${WRKSRC}/orcasetup/${SCRIPT} ${PREFIX}/lib/flash
.endfor
	@${INSTALL_DATA} ${WRKSRC}/orcasetup/flashdocs/* ${PREFIX}/lib/flash/flashdocs/
	@${INSTALL_MAN} ${WRKSRC}/flash.1 ${PREFIX}/man/man1
	@${INSTALL_PROGRAM} ${WRKSRC}/flash ${PREFIX}/bin

post-install:
	@${ECHO} "Updating /etc/shells"
	@${CP} /etc/shells /etc/shells.bak
	@(${GREP} -v ${PREFIX}/bin/flash /etc/shells.bak; \
	${ECHO} ${PREFIX}/bin/flash) > /etc/shells
	@${RM} /etc/shells.bak
	@${ECHO}
	@${ECHO} "  -------------------- WARNING --------------------------  "
	@${ECHO} "This software is not yet ready-to-go on your system. You "
	@${ECHO} "need to configure flash in ${PREFIX}/lib/flash in order for"
	@${ECHO} "it to work properly."
	@${ECHO}

.include <bsd.port.post.mk>
