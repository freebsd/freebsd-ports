# New ports collection makefile for:	fspd
# Date created:				2001-04-10
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	fspd
PORTVERSION=	2.8.1.3
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.netsw.org/net/ip/filetrans/fsp/
DISTNAME=	fsp.281-B3

MAINTAINER=	trevor@FreeBSD.org

ALL_TARGET=	fspserver
DOCDIR=		share/doc/${PORTNAME}
DOCFILES=	BETA.README ChangeLog FILES INFO TODO INSTALL MACHINES
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
MAN1=		fspd.1
PLIST=		${WRKDIR}/pkg-plist
WRKSRC=		${WRKDIR}/2.8.1

do-patch:
	${REINPLACE_CMD} -e "s:/usr/fsp:${LOCALBASE}/etc:g" \
		${WRKSRC}/include/server_conf.h

pre-install:
	${ECHO_CMD} "sbin/fspd" > ${PLIST}
.if !defined(NOPORTDOCS)
.for i in ${DOCFILES}
	${ECHO_CMD} ${DOCDIR}/${i} >> ${PLIST}
.endfor
	${ECHO_CMD} share/examples/fspd/example.conf >> ${PLIST}
	${ECHO_CMD} @dirrm ${DOCDIR} >> ${PLIST}
	${ECHO_CMD} @dirrm share/examples/fspd >> ${PLIST}
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/server/fspd ${LOCALBASE}/sbin
.if !defined(NO_INSTALL_MANPAGES)
	${INSTALL_MAN} ${WRKSRC}/man/man1/fspd.1 ${LOCALBASE}/man/man1/
.endif
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/examples/fspd ${PREFIX}/${DOCDIR}
.for i in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/${i} ${PREFIX}/${DOCDIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/example.conf ${PREFIX}/share/examples/fspd
.endif

.include <bsd.port.mk>
