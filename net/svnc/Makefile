# New ports collection makefile for:	svnc
# Date created:				2000-10-22
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	svnc
PORTVERSION=	0.1
CATEGORIES=	net
MASTER_SITES=	http://www.uk.research.att.com/vnc/contrib/ \
		http://www.uk.research.att.com/vnc/dist/
DISTFILES=	${PORTNAME}-${PORTVERSION}.tgz \
		vnc-3.3.3r1_unixsrc.tgz

MAINTAINER=	trevor@FreeBSD.org

LIB_DEPENDS=	vga.1:${PORTSDIR}/graphics/svgalib

DOCFILES=	README
DOCDIR=		share/doc/${PORTNAME}/

PLIST=		${WRKDIR}/pkg-plist
USE_XLIB=	yes
WRKSRC=		${WRKDIR}/svncviewer

do-patch:
	${PERL} -pi -e "s:include <vncviewer.h>:include \"vncviewer.h\":g" \
		${WRKSRC}/*c

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
	${ECHO} "bin/svncviewer" > ${PLIST}
.if !defined(NOPORTDOCS)
.for i in ${DOCFILES}
	${ECHO} -n ${DOCDIR} >> ${PLIST}
	${ECHO} ${i} >> ${PLIST}
.endfor
	${ECHO} -n "@dirrm " >> ${PLIST}
	${ECHO} ${DOCDIR} >> ${PLIST}
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
