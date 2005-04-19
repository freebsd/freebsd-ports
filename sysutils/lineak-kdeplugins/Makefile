# New ports collection makefile for:	lineak_kdeplugins
# Date created:		2004-12-29
# Whom:			Kay Lehmann <kay_lehmann@web.de>
#
# $FreeBSD$
#

PORTNAME=	lineak_kdeplugins
PORTVERSION=	0.8.3
PORTREVISION=	1
CATEGORIES=	sysutils deskutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	lineak
DIST_SUBDIR=	lineak

MAINTAINER=	kay_lehmann@web.de
COMMENT=	KDE plugins for lineakd

LIB_DEPENDS=	lineak.8:${PORTSDIR}/sysutils/lineakd

USE_KDELIBS_VER=3
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"
CONFIGURE_ARGS+=	--program-prefix=''
USE_REINPLACE=	yes
USE_LIBTOOL_VER=15

MAN1=		lineak_kdeplugins.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
IGNORE=		"Needs KDE to be compiled with gcc 3.4"
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-ldl||' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|-O2||' ${WRKSRC}/configure

.include <bsd.port.post.mk>
