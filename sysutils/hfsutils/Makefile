# Created by: Vanilla I. Shu <vanilla@MinJe.com.TW>
# $FreeBSD$

PORTNAME=	hfsutils
PORTVERSION=	3.2.6
PORTREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.mars.org/pub/hfs/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utilities for accessing Apple's HFS volumes

LICENSE=	GPLv2

CONFLICTS=	hfs-[0-9]*

GNU_CONFIGURE=	yes
USE_GMAKE=	yes			# passing -jX breaks BSD make(1)
ALL_TARGET=	all hfsck/hfsck

MAN1=		hattrib.1 \
		hcd.1 \
		hcopy.1 \
		hdel.1 \
		hdir.1 \
		hformat.1 \
		hfsutils.1 \
		hls.1 \
		hmkdir.1 \
		hmount.1 \
		hpwd.1 \
		hrename.1 \
		hrmdir.1 \
		humount.1 \
		hvol.1

OPTIONS_DEFINE=	TCLTK DEVLIBS DOCS

TCLTK_DESC=	Enable Tcl interface (HFS "shell") and Tk-based GUI
DEVLIBS_DESC=	Install developer libraries and header files

PORTDOCS=	*

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MTCLTK}
CATEGORIES+=	tcl tk

USE_TCL=	84+
USE_TK=		84+

CONFIGURE_ARGS=	--with-tcl=${TCL_LIBDIR} --with-tk=${TK_LIBDIR}
CPPFLAGS+=	-I${LOCALBASE}/include

MAN1+=		hfs.1 \
		hfssh.1 \
		xhfs.1

PLIST_FILES+=	bin/hfs \
		bin/hfssh \
		bin/xhfs
.else
CONFIGURE_ARGS=	--without-tcl --without-tk
.endif

.if ${PORT_OPTIONS:MDEVLIBS}
CONFIGURE_ARGS+=	--enable-devlibs

PLIST_FILES+=	include/hfs.h \
		include/rsrc.h \
		lib/libhfs.a \
		lib/librsrc.a
.endif

post-patch:
# Unbreak against Tcl 8.6
	@${ECHO_CMD} '#define USE_INTERP_RESULT 1' >> ${WRKSRC}/config.h.in

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hfsck/hfsck ${PREFIX}/bin
.if ${PORT_OPTIONS:MTCLTK}
	@${CHMOD} 755 ${PREFIX}/bin/hfs
.endif
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.  for f in BLURB CHANGES README TODO doc/*.txt
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.  endfor
.endif

.include <bsd.port.mk>
