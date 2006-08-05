# New ports collection makefile for: bibletime
# Date created:   3 May 2002
# Whom:           Willem van Engen <wvengen@stack.nl>
#
# $FreeBSD$
#

PORTNAME=	bibletime
PORTVERSION=	1.5.3
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	thomas@goodking.ca
COMMENT=	A powerful Bible study application for KDE3

RUN_DEPENDS=	${LOCALBASE}/lib/libsword.so:${PORTSDIR}/misc/sword
BUILD_DEPENDS=	${RUN_DEPENDS}

USE_KDELIBS_VER=3
USE_AUTOTOOLS=	libtool:15
USE_GMAKE=	yes
USE_BZIP2=	yes
INSTALLS_ICONS=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		fails to compile under FreeBSD 4.x
.endif

post-patch:
	@${REINPLACE_CMD} -e "s^-lpthread^${PTHREAD_LIBS}^g" ${WRKSRC}/configure
	@${REINPLACE_CMD} -e "s^-lpthread^${PTHREAD_LIBS}^g" ${WRKSRC}/bibletime/Makefile.in

.include <bsd.port.post.mk>
