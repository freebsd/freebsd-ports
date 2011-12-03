# New ports collection makefile for:	w_scan
# Date created:		Wed Apr 14 18:11:42 CEST 2010
# Whom:			Juergen Lock <nox@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	w_scan
PORTVERSION=	20111203
CATEGORIES=	multimedia
MASTER_SITES=	http://wirbel.htpc-forum.de/w_scan/

MAINTAINER=	nox@FreeBSD.org
COMMENT=	Perform frequency scans for DVB and ATSC transmissions

BUILD_DEPENDS=  ${LOCALBASE}/include/linux/dvb/frontend.h:${PORTSDIR}/multimedia/v4l_compat

OPTIONS=	LINUX "Install Linux binary too (linux-w_scan)" off

.include <bsd.port.options.mk>

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
PATCH_STRIP=	-p1
USE_GETTEXT=	yes
CPPFLAGS+=	-I"${LOCALBASE}/include"
LDFLAGS+=	-L"${LOCALBASE}/lib\ -liconv"
PORTDOCS=	COPYING ChangeLog README
PLIST_FILES=	bin/${PORTNAME}
MAN1=		w_scan.1
MAKE_JOBS_SAFE=	yes

.if defined(WITH_LINUX)
USE_LINUX=	yes
RUN_DEPENDS+=	linux_dvbwrapper-kmod>=1.0:${PORTSDIR}/multimedia/linux_dvbwrapper-kmod
PLIST_FILES+=	bin/linux-${PORTNAME}
.endif

post-patch:
	${REINPLACE_CMD} -f ${FILESDIR}/types.sed ${WRKSRC}/configure ${WRKSRC}/*.c ${WRKSRC}/*.h
	${CP} ${WRKSRC}/${PORTNAME} ${WRKSRC}/linux-${PORTNAME}

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR})
.endif
.if defined(WITH_LINUX)
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} linux-${PORTNAME} ${PREFIX}/bin)
.endif

.include <bsd.port.mk>
