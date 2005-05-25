# New ports collection makefile for:	kdar
# Date created:		2004-01-26
# Whom:			Kay Lehmann <kay_lehmann@web.de>
#
# $FreeBSD$
#

PORTNAME=	kdar
PORTVERSION=	2.0.4
CATEGORIES=	sysutils kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	kdar
DISTNAME=	kdar-${PORTVERSION:S/.b./-beta/}

MAINTAINER=	kay_lehmann@web.de
COMMENT=	KDar is KDE-based backuptool using libdar

LIB_DEPENDS=	dar.3:${PORTSDIR}/sysutils/dar

USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_KDEBASE_VER=	3
USE_REINPLACE=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
IGNORE=		Does not build on FreeBSD 4.X
.endif

post-patch:
	@${REINPLACE_CMD} -e "s,-lpthread,${PTHREAD_LIBS},g" ${WRKSRC}/configure

.include <bsd.port.post.mk>
