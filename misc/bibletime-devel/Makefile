# New ports collection makefile for: bibletime
# Date created:   3 May 2002
# Whom:           Willem van Engen <wvengen@stack.nl>
#
# $FreeBSD$
#

PORTNAME=	bibletime
PORTVERSION=	1.2.2
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	wvengen@stack.nl
COMMENT=	A powerful Bible study application for KDE3

LIB_DEPENDS=	sword.1:${PORTSDIR}/misc/sword
.if !defined(NOPORTDOCS)
RUN_DEPENDS=	${LOCALBASE}/share/doc/HTML/en/bibletime:${PORTSDIR}/misc/bibletime-doc
.endif

USE_KDELIBS_VER=3
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_BZIP2=	yes
USE_REINPLACE=	yes
CONFIGURE_ARGS+=--program-transform-name="" \
		--with-sworddir=${PREFIX}

post-patch:
	@${REINPLACE_CMD} -e "s^-lpthread^${PTHREAD_LIBS}^g" ${WRKSRC}/configure
	@${REINPLACE_CMD} -e "s^-lpthread^${PTHREAD_LIBS}^g" ${WRKSRC}/bibletime/Makefile.in

.include <bsd.port.mk>
