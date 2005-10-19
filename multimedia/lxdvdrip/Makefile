# New ports collection makefile for:	multimedia/lxdvdrip
# Date created:				26.01.2005
# Whom:					Ulrich Spoerlein <q@uni.de>
#
# $FreeBSD$
#

PORTNAME=	lxdvdrip
PORTVERSION=	1.47
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	http://download.berlios.de/lxdvdrip/
EXTRACT_SUFX=	.tgz

MAINTAINER=	serge.gagnon@b2b2c.ca
COMMENT=	Command Line Tool to make a copy from a Video DVD

LIB_DEPENDS=	dvdread.3:${PORTSDIR}/multimedia/libdvdread
RUN_DEPENDS=	streamdvd:${PORTSDIR}/multimedia/streamdvd \
		transcode:${PORTSDIR}/multimedia/transcode \
		dvdauthor:${PORTSDIR}/multimedia/dvdauthor \
		growisofs:${PORTSDIR}/sysutils/dvd+rw-tools \
		mpgtx:${PORTSDIR}/multimedia/mpgtx

SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

WRKSRC=		${WRKDIR}/${PORTNAME}
VAMPSRC=	vamps.c requant.c
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS} -ldvdread -lm

PORTDOCS=	Changelog.de Changelog.en Changelog.fr \
		README.de  README.en README.fr \
		README.dvdwizard.DE README.dvdwizard.EN README.dvdwizard.FR \
		TODO freebsd.doc
MAN1=		lxdvdrip.1

.include <bsd.port.pre.mk>

# vamps needs strtof()
.if ${OSVERSION} > 500000
PLIST_SUB=	VAMPS=""
.else
PLIST_SUB=	VAMPS="@comment "
.endif

do-build:
	${CC} ${CFLAGS} ${LDFLAGS} -o ${WRKSRC}/${PORTNAME} ${WRKSRC}/${PORTNAME}.c
	${CC} ${CFLAGS} ${LDFLAGS} -o ${WRKSRC}/lxac3scan ${WRKSRC}/lxac3scan.c
.if ${OSVERSION} > 500000
.for f in ${VAMPSRC}
	${CC} ${CFLAGS} -c ${WRKSRC}/vamps/${f} -o ${WRKSRC}/vamps/${f:C/\.c$/.o/}
.endfor
	${CC} ${CFLAGS} ${LDFLAGS} -o ${WRKSRC}/vamps/vamps ${VAMPSRC:C/(.*)\.c$/${WRKSRC}\/vamps\/\1.o/}
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
	${INSTALL_PROGRAM} ${WRKSRC}/vamps/vamps ${PREFIX}/bin
.endif
	@${MKDIR} ${EXAMPLESDIR}
.for f in lxdvdrip.conf.DE lxdvdrip.conf.EN lxdvdrip.conf.FR
	${INSTALL_DATA} ${WRKSRC}/doc-pak/${f} ${EXAMPLESDIR}
.endfor

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc-pak/${f} ${DOCSDIR}
.endfor
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
