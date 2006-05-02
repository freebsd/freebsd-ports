# New ports collection makefile for:	cphone
# Date created:		Thu May 24 15:50:00 BST 2000
# Whom:			Roger Hardiman <roger@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cphone
DISTVERSION=	0.3.2.cvs.20060407
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.frm2.tum.de/pub/jpulz/FreeBSD/distfiles/

MAINTAINER=	Joerg.Pulz@frm2.tum.de
COMMENT=	H323 Video Conferencing Program which uses QT

LIB_DEPENDS=	h323_r.1:${PORTSDIR}/net/openh323
BUILD_DEPENDS=	qmake:${PORTSDIR}/devel/qmake

PLIST_FILES=	bin/cphone
USE_BZIP2=	yes
USE_BISON=	yes
USE_QT_VER=	3
USE_GMAKE=	yes
ALL_TARGET=	optshared
MAKE_ENV=	QTDIR=${X11BASE} \
		PWLIBDIR=${LOCALBASE}/share/pwlib \
		OPENH323DIR=${LOCALBASE}/share/openh323 \
		SYSLIBDIR=${LOCALBASE}/lib
MAKE_ARGS=	OSTYPE=${OPSYS} MACHTYPE=${ARCH:S/i386/x86/} \
		OSRELEASE=${OSVERSION} CPLUS=${CXX}

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e '/graphdisplay.h/d' -e '/videodisplay.h/d' \
		-e '/labeldisplay.h/d' ${WRKSRC}/mainwindow.ui \
		${WRKSRC}/settings.ui ${WRKSRC}/statistics.ui

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/obj_r/cphone ${PREFIX}/bin

.include <bsd.port.post.mk>
