# New ports collection makefile for:	svnc
# Date created:				2000-10-22
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	svnc
PORTVERSION=	0.1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_LOCAL:S/$/:svnc/} \
		${MASTER_SITE_NETBSD:S/$/:vnc/}:vnc
MASTER_SITE_SUBDIR=	./:vnc trevor/:svnc
DISTFILES=	${PORTNAME}-${PORTVERSION}.tgz:svnc \
		vnc-3.3.3r1_unixsrc.tgz:vnc

MAINTAINER=	ports@FreeBSD.org
COMMENT=	VNC viewer for SVGAlib

BUILD_DEPENDS=	${X11BASE}/include/X11/keysym.h:${PORTSDIR}/x11/XFree86
LIB_DEPENDS=	vga.1:${PORTSDIR}/graphics/svgalib

DOCFILES=	README
DOCDIR=		share/doc/${PORTNAME}/
ONLY_FOR_ARCHS=	i386
PLIST=		${WRKDIR}/pkg-plist
WRKSRC=		${WRKDIR}/svncviewer

do-patch:
.for ii in args kbd listen rfbproto sockets svga svncviewer vncviewer
	@${MV} ${WRKSRC}/${ii}.c ${WRKSRC}/${ii}.c.orig
	@${SED} -e "s:include <vncviewer.h>:include \"vncviewer.h\":g" \
		< ${WRKSRC}/${ii}.c.orig > ${WRKSRC}/${ii}.c
.endfor

do-build:
	cd ${WRKDIR}/vnc_unixsrc/libvncauth && \
		${CC} -I. -I../include -c vncauth.c && \
		${CC} -I. -I../include -c d3des.c && \
		ar clq libvncauth.a  *.o && \
		ranlib libvncauth.a
	cd ${WRKSRC} && \
		${CC} -Wall -L${PREFIX}/lib \
		-I${X11BASE}/include -I${PREFIX}/include \
		-I${WRKSRC} -I${WRKSRC}/../vnc_unixsrc/include/ \
		-I${WRKSRC}/../vnc_unixsrc/vncviewer/ \
		-lvga -lvgagl \
		-o svncviewer \
		args.c rfbproto.c sockets.c svncviewer.c svga.c kbd.c \
		${WRKDIR}/vnc_unixsrc/libvncauth/libvncauth.a

pre-install:
	${ECHO_CMD} "bin/svncviewer" > ${PLIST}
.if !defined(NOPORTDOCS)
.for i in ${DOCFILES}
	${ECHO_CMD} -n ${DOCDIR} >> ${PLIST}
	${ECHO_CMD} ${i} >> ${PLIST}
.endfor
	${ECHO_CMD} -n "@dirrm " >> ${PLIST}
	${ECHO_CMD} ${DOCDIR} >> ${PLIST}
.endif

do-install:
	${INSTALL} -c -g wheel -o root -m 4755 ${WRKSRC}/svncviewer ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/${DOCDIR}
.for i in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/${i} ${PREFIX}/${DOCDIR}
.endfor
.endif

.include <bsd.port.mk>
