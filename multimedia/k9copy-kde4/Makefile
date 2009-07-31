# New ports collection makefile for:	k9copy
# Date created:				19 Dec 2005
# Whom:			Alexander V. Ribchansky <triosoft@triosoft.com.ua>
#
# $FreeBSD$

PORTNAME=	k9copy
PORTVERSION=	1.0.4
PORTREVISION=	5
CATEGORIES=	multimedia kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	triosoft@triosoft.com.ua
COMMENT=	A DVD-9 to DVD-5 shrinking application for KDE

LIB_DEPENDS=	dvdread.4:${PORTSDIR}/multimedia/libdvdread
RUN_DEPENDS=	growisofs:${PORTSDIR}/sysutils/dvd+rw-tools \
		dvdauthor:${PORTSDIR}/multimedia/dvdauthor \
		vamps:${PORTSDIR}/multimedia/vamps

USE_KDELIBS_VER=3
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:15
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e 's,-O2,,g ; \
		s,-lpthread,${PTHREAD_LIBS},g' ${WRKSRC}/${CONFIGURE_SCRIPT}
	@${REINPLACE_CMD} -e \
		's,$$(LIB_KDEUI),$$(LIB_KDEUI) $$(LIBPTHREAD) -lcam,g' \
		${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
