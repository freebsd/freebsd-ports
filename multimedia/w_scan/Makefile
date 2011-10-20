# New ports collection makefile for:	w_scan
# Date created:		Wed Apr 14 18:11:42 CEST 2010
# Whom:			Juergen Lock <nox@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	w_scan
PORTVERSION=	20111011
CATEGORIES=	multimedia
MASTER_SITES=	http://wirbel.htpc-forum.de/w_scan/

MAINTAINER=	nox@FreeBSD.org
COMMENT=	Perform frequency scans for DVB and ATSC transmissions

BUILD_DEPENDS=  ${LOCALBASE}/include/linux/dvb/frontend.h:${PORTSDIR}/multimedia/v4l_compat

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

post-patch:
	${REINPLACE_CMD} -f ${FILESDIR}/types.sed ${WRKSRC}/configure ${WRKSRC}/*.c ${WRKSRC}/*.h

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR})
.endif

.include <bsd.port.mk>
