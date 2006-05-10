# New ports collection makefile for:	multimedia/lxdvdrip
# Date created:				26.01.2005
# Whom:					Ulrich Spoerlein <q@uni.de>
#
# $FreeBSD$
#

PORTNAME=	lxdvdrip
PORTVERSION=	1.51
PORTREVISION=	3
CATEGORIES=	multimedia
MASTER_SITES=	http://download.berlios.de/lxdvdrip/ \
		ftp://quenix2.dyndns.org/FreeBSD/ports/distfiles/
EXTRACT_SUFX=	.tgz

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	Command Line Tool to make a copy from a Video DVD

LIB_DEPENDS=	dvdread.3:${PORTSDIR}/multimedia/libdvdread
RUN_DEPENDS=	buffer:${PORTSDIR}/misc/buffer \
		dvdauthor:${PORTSDIR}/multimedia/dvdauthor \
		dvdbackup:${PORTSDIR}/sysutils/dvdbackup \
		growisofs:${PORTSDIR}/sysutils/dvd+rw-tools \
		mpgtx:${PORTSDIR}/multimedia/mpgtx \
		mplayer:${PORTSDIR}/multimedia/mplayer \
		transcode:${PORTSDIR}/multimedia/transcode

SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

WRKSRC=		${WRKDIR}/${PORTNAME}
VAMPSRC=	vamps.c requant.c
LXDVDRIPSRC=	${PORTNAME}.c streamanalyze.c
CFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS} -ldvdread -lm

PORTDOCS=	Changelog.de Changelog.en Changelog.fr \
		README.de  README.en README.fr \
		README.dvdwizard.DE README.dvdwizard.EN README.dvdwizard.FR \
		TODO freebsd.doc
MAN1=		lxdvdrip.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} > 500000
PLIST_FILES=	bin/vamps_${PORTNAME} \
		bin/play_cell_${PORTNAME}
.endif

post-patch:
	@${REINPLACE_CMD} -E \
		-e 's|playwave[[:space:]]+-r[[:space:]]+|wavplay -s|' \
		-e 's|playwave|wavplay|' \
		-e 's|/usr/local/share/lxdvdrip.wav|${DATADIR}/lxdvdrip.wav|' \
		${WRKSRC}/${PORTNAME}.c

do-build:
	${CC} ${CFLAGS} ${LDFLAGS} -o ${WRKSRC}/${PORTNAME} ${LXDVDRIPSRC:C/^/${WRKSRC}\//}
	${CC} ${CFLAGS} ${LDFLAGS} -o ${WRKSRC}/lxac3scan ${WRKSRC}/lxac3scan.c
.if ${OSVERSION} > 500000
.for f in ${VAMPSRC}
	${CC} ${CFLAGS} -c ${WRKSRC}/vamps/${f} -o ${WRKSRC}/vamps/${f:C/\.c$/.o/}
.endfor
	${CC} ${CFLAGS} ${LDFLAGS} -o ${WRKSRC}/vamps/vamps_${PORTNAME} ${VAMPSRC:C/(.*)\.c$/${WRKSRC}\/vamps\/\1.o/}
	${CC} ${CFLAGS} ${LDFLAGS} -o ${WRKSRC}/vamps/play_cell_${PORTNAME} ${WRKSRC}/vamps/play_cell.c
.endif

do-install:
.for f in lxdvdrip lxac3scan
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${PREFIX}/bin
.endfor
	${INSTALL_MAN} ${WRKSRC}/lxdvdrip.1 ${PREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/doc-pak/lxdvdrip.conf.EN ${PREFIX}/etc/lxdvdrip.conf.sample
.if !exists(${PREFIX}/etc/lxdvdrip.conf)
	${INSTALL_DATA} ${WRKSRC}/doc-pak/lxdvdrip.conf.EN ${PREFIX}/etc/lxdvdrip.conf
.endif
.if ${OSVERSION} > 500000
	${INSTALL_PROGRAM} ${WRKSRC}/vamps/vamps_${PORTNAME} ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/vamps/play_cell_${PORTNAME} ${PREFIX}/bin
.endif
	@${MKDIR} ${EXAMPLESDIR}
.for f in lxdvdrip.conf.DE lxdvdrip.conf.EN lxdvdrip.conf.FR
	${INSTALL_DATA} ${WRKSRC}/doc-pak/${f} ${EXAMPLESDIR}
.endfor
	@${MKDIR} ${DATADIR}
	@${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.wav ${DATADIR}

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc-pak/${f} ${DOCSDIR}
.endfor
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
