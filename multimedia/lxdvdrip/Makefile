# New ports collection makefile for:	multimedia/lxdvdrip
# Date created:				26.01.2005
# Whom:					Ulrich Spoerlein <q@uni.de>
#
# $FreeBSD$
#

PORTNAME=	lxdvdrip
PORTVERSION=	1.62
CATEGORIES=	multimedia
MASTER_SITES=	http://download.berlios.de/lxdvdrip/ \
		ftp://quenix2.dyndns.org/FreeBSD/ports/distfiles/
EXTRACT_SUFX=	.tgz

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Command Line Tool to make a copy from a Video DVD

LIB_DEPENDS=	dvdnav.4:${PORTSDIR}/multimedia/libdvdnav \
		dvdread.3:${PORTSDIR}/multimedia/libdvdread
RUN_DEPENDS=	buffer:${PORTSDIR}/misc/buffer \
		dvdauthor:${PORTSDIR}/multimedia/dvdauthor \
		growisofs:${PORTSDIR}/sysutils/dvd+rw-tools \
		mpgtx:${PORTSDIR}/multimedia/mpgtx \
		mplayer:${PORTSDIR}/multimedia/mplayer \
		transcode:${PORTSDIR}/multimedia/transcode

SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

WRKSRC=		${WRKDIR}/${PORTNAME}
VAMPSRC=	vamps.c requant.c
LXDVDRIPSRC=	cputest.c \
		dvdbackup.c \
		dvdcell.c \
		dvdcopy.c \
		dvdinfo.c \
		dvdtools.c \
		ifo.c \
		lxdvdrip.c \
		requant.c \
		streamanalyze.c \
		systools.c \
		tcmemcpy.c \
		vaporize.c
CFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS} -ldvdread -lm
MAKE_ENV+=	LDFLAGS="${LDFLAGS}"

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
	@${REINPLACE_CMD} -E \
		-e 's|^.+alloca.h.+$$||' \
		${WRKSRC}/dvdbackup.c
	@${REINPLACE_CMD} -E \
		-e 's|fopen64|fopen|' \
		${WRKSRC}/dvdinfo.c \
		${WRKSRC}/lxdvdrip.c
	@${REINPLACE_CMD} -E \
		-e 's|stat64|stat|' \
		${WRKSRC}/systools.c
	@${REINPLACE_CMD} -E \
		-e 's|uint([[:space:]]+)|unsigned int\1|g' \
		-e 's|int([[:digit:]]+)|int\1_t|' \
		${WRKSRC}/vamps/requant.c

do-install:
.for f in lxdvdrip lxac3scan
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${PREFIX}/bin
.endfor
	${INSTALL_MAN} ${WRKSRC}/lxdvdrip.1 ${PREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/doc-pak/lxdvdrip.conf.EN ${PREFIX}/etc/lxdvdrip.conf.sample
.if !exists(${PREFIX}/etc/lxdvdrip.conf)
	${INSTALL_DATA} ${WRKSRC}/doc-pak/lxdvdrip.conf.EN ${PREFIX}/etc/lxdvdrip.conf
.endif
# binaries
.if ${OSVERSION} > 500000
	${INSTALL_PROGRAM} ${WRKSRC}/vamps/vamps_${PORTNAME} ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/vamps/play_cell_${PORTNAME} ${PREFIX}/bin
.endif
	${INSTALL_PROGRAM} ${WRKSRC}/dvdbackup/dvdbackup_${PORTNAME} ${PREFIX}/bin
# examples
	@${MKDIR} ${EXAMPLESDIR}
.for f in lxdvdrip.conf.DE lxdvdrip.conf.EN lxdvdrip.conf.FR
	${INSTALL_DATA} ${WRKSRC}/doc-pak/${f} ${EXAMPLESDIR}
.endfor
# data
	@${MKDIR} ${DATADIR}
	@${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.wav ${DATADIR}
# docs
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc-pak/${f} ${DOCSDIR}
.endfor
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
