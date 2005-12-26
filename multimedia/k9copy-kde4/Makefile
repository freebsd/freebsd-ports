# New ports collection makefile for:	k9copy
# Date created:				19 Dec 2005
# Whom:			Alexander V. Ribchansky <triosoft@triosoft.com.ua>
#
# $FreeBSD$

PORTNAME=	k9copy
PORTVERSION=	1.0.1
CATEGORIES=	multimedia kde
MASTER_SITES=	http://k9copy.free.fr/

MAINTAINER=	triosoft@triosoft.com.ua
COMMENT=	A DVD-9 to DVD-5 shrinking application for KDE

LIB_DEPENDS=	dvdread.3:${PORTSDIR}/multimedia/libdvdread
RUN_DEPENDS=	growisofs:${PORTSDIR}/sysutils/dvd+rw-tools \
		dvdauthor:${PORTSDIR}/multimedia/dvdauthor

USE_KDELIBS_VER=3
USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}b

post-patch:
	@${REINPLACE_CMD} -e 's,-O2,,g ; \
		s,-lpthread,${PTHREAD_LIBS},g' ${WRKSRC}/${CONFIGURE_SCRIPT}
	@${REINPLACE_CMD} -e \
		's,$$(LIB_KDEUI),$$(LIB_KDEUI) $$(LIBPTHREAD) -lcam,g' \
		${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
