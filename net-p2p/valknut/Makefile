# ex: ts=8
# New ports collection makefile for:    dcgui
# Date created:                         Wed 10 Jul 2002
# Whom:	Sverrir Valgeirsson <e96sv@yahoo.se> and
#	Amar Takhar <verm@drunkmonk.net> et al
#
# $FreeBSD$
#

PORTNAME=	valknut
PORTVERSION=	0.4.4
CATEGORIES=	net-p2p
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	wxdcgui
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	A Direct Connect client QT GUI

LIB_DEPENDS=	dc.0:${PORTSDIR}/net-p2p/dclib \
		xml2.5:${PORTSDIR}/textproc/libxml2

WRKSRC=	${WRKDIR}/${DISTNAME}

MAN1=	valknut.1

USE_QT_VER=	4
QT_COMPONENTS=	corelib gui network qt3support moc uic rcc linguist
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_PERL5_BUILD=yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libdc=${LOCALBASE} \
		--x-libraries=${LOCALBASE}/lib \
		--x-includes=${LOCALBASE}/include
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}" \
		RCC="${LOCALBASE}/bin/rcc" LRELEASE="${LOCALBASE}/bin/lrelease-qt4"

CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

post-patch:
	@${REINPLACE_CMD} -e 's/-O2//g; s/-lpthread/${PTHREAD_LIBS}/g' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.mk>
