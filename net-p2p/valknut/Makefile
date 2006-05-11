# New ports collection makefile for:    dcgui
# Date created:                         Wed 10 Jul 2002
# Whom:	Sverrir Valgeirsson <e96sv@yahoo.se> and
#	Amar Takhar <verm@drunkmonk.net> et al
#
# $FreeBSD$
#

PORTNAME=	valknut
PORTVERSION=	0.3.7
CATEGORIES=	net-p2p
MASTER_SITES=	http://download.berlios.de/dcgui/ \
		http://www.hitnet.rwth-aachen.de/~brueffer/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Direct Connect client QT GUI

LIB_DEPENDS=	dc.0:${PORTSDIR}/net-p2p/dclib \
		xml2.5:${PORTSDIR}/textproc/libxml2

USE_QT_VER=	3
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_PERL5_BUILD=yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libdc=${LOCALBASE} \
		--x-libraries=${X11BASE}/lib --x-includes=${X11BASE}/include

CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

post-patch:
	@${REINPLACE_CMD} -e 's/-O2//g; s/-lpthread/${PTHREAD_LIBS}/g' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.mk>
