# New ports collection makefile for:   kmerlin
# Date created:        20 September 2002
# Whom:                Cédric Lamalle
#
# $FreeBSD$
#

PORTNAME=	kmerlin
PORTVERSION=	1.4.2
PORTREVISION=	6
CATEGORIES=	net-im
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An IM (Instant Messenger) KDE client for the Microsoft MSN Network

USE_XORG=	xscrnsaver
USE_KDELIBS_VER=3
USE_AUTOTOOLS=	libtool:22
USE_GMAKE=	yes

CONFIGURE_ARGS+=	--prefix=${LOCALBASE}
CONFIGURE_ENV=	LDFLAGS="${PTHREAD_LIBS}"

post-patch:
.for i in replacepage identityeditdialog identitysetting \
	chatsetting systemnotification
	@${RM} ${WRKSRC}/src/setting/${i}.h ${WRKSRC}/src/setting/${i}.cpp
.endfor
	@${RM} ${WRKSRC}/src/login.h ${WRKSRC}/src/login.cpp
	@${REINPLACE_CMD} -e 's|-O2||g; s|-lpthread|${PTHREAD_LIBS}|g' \
		${WRKSRC}/${CONFIGURE_SCRIPT}
	@${REINPLACE_CMD} -e 's|;;|;|g;' ${WRKSRC}/src/kmerlindock.h

.include <bsd.port.mk>
