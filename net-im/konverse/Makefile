# New ports collection makefile for:	konverse
# Date created:				30 May 2001
# Whom:				Hye-Shik Chang <perky@python.or.kr>
#
# $FreeBSD$
#

PORTNAME=	konverse
PORTVERSION=	0.2
PORTREVISION=	8
CATEGORIES=	net-im kde
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	KDE Jabber Client

USE_KDELIBS_VER=3
USE_AUTOTOOLS=	libtool:22
USE_GMAKE=	yes

CONFIGURE_ARGS+=--with-extra-includes=${LOCALBASE}/include \
		--with-qt-libraries=${QT_PREFIX}/lib

pre-patch:
	${REINPLACE_CMD} -e 's|-lqt|-lqt-mt ${PTHREAD_LIBS}|' \
		-e 's/libqt\.\*/libqt-mt.*/' ${WRKSRC}/configure
	${REINPLACE_CMD} -e 's/\(LDADD.*\)-ldl/\1/' \
		-e 's|-lqt|${PTHREAD_LIBS}|' ${WRKSRC}/konverse/Makefile.in
	${REINPLACE_CMD} -e 's/\(QDateTime.*\)timezone/\1local-\>tm_gmtoff/g' \
		${WRKSRC}/konverse/jabbercore.cpp
.for f in konverse/rostertree.h konverse/dlgchat.h
	${REINPLACE_CMD} -e 's/ktmainwindow\.h/kmainwindow.h/g' ${WRKSRC}/${f}
.endfor

.include <bsd.port.mk>
