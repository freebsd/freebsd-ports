# New ports collection makefile for:	gnomem-commander
# Date created:		23 April 2002
# Whom:			Edgardo Garcia Hoeffler <edybsd@yahoo.com.ar>
#
# $FreeBSD$
#

PORTNAME=	gnome-commander
PORTVERSION=	0.9.6
CATEGORIES=	x11-fm gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gnome-commander

MAINTAINER=	edybsd@yahoo.com.ar

.if defined(WITH_FAM)
LIB_DEPENDS=	fam:${PORTSDIR}/devel/fam
.endif

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	yes
GNU_CONFIGURE=	yes

pre-patch:
	@find ${WRKSRC} -name "Makefile.in*" | xargs ${PERL} -pi -e \
		's|\$\(datadir\)/gnome/|\$\(datadir\)/|g ; \
		 s|\$\(datadir\)/locale|\$\(prefix\)/share/locale|g'

.include <bsd.port.mk>
