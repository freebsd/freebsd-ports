# New ports collection makefile for:    cdrdao
# Date created:         7 April 1999
# Whom:                 futatuki
#
# $FreeBSD$
#

PORTNAME=		cdrdao
PORTVERSION=		1.1.3
CATEGORIES=		audio
MASTER_SITES=		http://www.ping.de/sites/daneb/
EXTRACT_SUFX=		.src.tar.gz

MAINTAINER=		futatuki@debug.gr.jp

BUILD_DEPENDS=		antlr:${PORTSDIR}/devel/pccts\
			dlg:${PORTSDIR}/devel/pccts

WRKSRC=         	${WRKDIR}/cdrdao-1.1.3

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
MAN1=		cdrdao.1

.include <bsd.port.pre.mk>

.if exists(${X11BASE}/include/gtk--.h)
XCDRDAO=		yes
.endif

.if defined(PACKAGE_BUILDING)
XCDRDAO=		yes
.endif

.if defined(XCDRDAO)
USE_NEWGCC=	yes
LIB_DEPENDS+=		gtkmm-1.2:${PORTSDIR}/x11-toolkits/gtk--
MAN1+=		xcdrdao.1
PLIST=${PKGDIR}/PLIST.xcdrdao
.else
CONFIGURE_ARGS= 	--disable-gtkmmtest
.endif

.if defined(WITHOUT_SCGLIB) && ${OSVERSION} > 300000
CONFIGURE_ARGS+= 	--without-scglib
.endif

.if defined(WITHOUT_PTHREADS) && ${OSVERSION} > 320000
CONFIGURE_ARGS+=	--without-posix-threads
.endif

pre-fetch:
	@${ECHO_MSG} "If you don't want to use Joerg Schilling's SCSI library,"
	@${ECHO_MSG} "set WITHOUT_SCGLIB=yes."
	@${ECHO_MSG} "If you don't want to use pthreads, set WITHOUT_PTHREADS=yes."
.if !defined(XCDRDAO)
	@${ECHO_MSG} "To build the graphical X toc file editor, xcdrdao, type:"
	@${ECHO_MSG} "    make XCDRDAO=yes."
.else
	@${ECHO_MSG} "Building with xcdrdao"
.endif

.if ${MACHINE_ARCH} == "alpha"
post-extract:
	@(cd ${WRKSRC}/scsilib/RULES; \
	  ln -sf i386-freebsd-cc.rul alpha-freebsd-cc.rul)
.endif

post-install:
	strip $(PREFIX)/bin/cdrdao
.if defined(XCDRDAO)
	strip $(PREFIX)/bin/xcdrdao
.endif
	@${MKDIR} ${PREFIX}/share/doc/cdrdao
.for i in COPYING CREDITS INSTALL README README.FreeBSD README.PlexDAE \
	Release-1.1.0 Release-1.1.2 Release-1.1.3
	@${INSTALL_DATA} ${WRKSRC}/$i ${PREFIX}/share/doc/cdrdao/
.endfor
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
