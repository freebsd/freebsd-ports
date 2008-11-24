# ex: ts=8
# New ports collection makefile for:    dcgui
# Date created:                         Wed 10 Jul 2002
# Whom:	Sverrir Valgeirsson <e96sv@yahoo.se> and
#	Amar Takhar <verm@drunkmonk.net> et al
#
# $FreeBSD$
#

PORTNAME=	valknut
PORTVERSION=	0.4.8
CATEGORIES=	net-p2p
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	wxdcgui
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	A Direct Connect client QT GUI

LIB_DEPENDS=	dc.4:${PORTSDIR}/net-p2p/dclib \
		xml2.5:${PORTSDIR}/textproc/libxml2

WRKSRC=	${WRKDIR}/${DISTNAME}

MAN1=	valknut.1

USE_QT_VER=	4
QT_COMPONENTS=	corelib gui network qt3support moc uic rcc linguist
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_PERL5_BUILD=yes
USE_AUTOTOOLS=	autoconf:262
INSTALLS_ICONS=	yes
CFLAGS+=	-I${QT_INCDIR}
LDFLAGS+=	-L${QT_LIBDIR}
CONFIGURE_ENV=	CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}" ACLOCAL=true \
		AUTOCONF=true AUTOMAKE=true AUTOHEADER=true \
		DCLIB_CFLAGS="-I${LOCALBASE}/include"

post-patch:
	${REINPLACE_CMD} -e 's|-O2||g; s|-lpthread|${PTHREAD_LIBS}|g;\
	    s|-D_XOPEN_SOURCE=500||g' \
	    ${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT} \
	    ${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}.in

.include <bsd.port.mk>
