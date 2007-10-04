# New ports collection makefile for:	gtkyahoo
# Date created:			18 August 1999
# Whom:				dannyman@dannyland.org
#
# $FreeBSD$
#

PORTNAME=	gtkyahoo
PORTVERSION=	0.18.3
PORTREVISION=	2
CATEGORIES=	net-im
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gtkyahoo

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Yahoo Messenger Client using GTK

USE_X_PREFIX=	yes
USE_GNOME=	gtk12
USE_BISON=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
ONLY_FOR_ARCHS=	i386

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 700042
BROKEN=		Does not compile with GCC 4.2
.endif

post-patch:
	@${REINPLACE_CMD} -e '/@INSTALL@/s/$$INSTALL/${INSTALL}/' \
		${WRKSRC}/libyahoo/configure

.include <bsd.port.post.mk>
