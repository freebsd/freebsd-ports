# New ports collection makefile for:	koncd
# Date created:				2 April 2001
# Whom:					Dmitry Sivachenko <demon@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	koncd
PORTVERSION=	0.7.1
CATEGORIES=	sysutils kde
MASTER_SITES=	http://www.koncd.de/download/ \
		ftp://apps.kde.com/pub/Multimedia/Audio/Burners_Rippers/KOnCD/

MAINTAINER=	demon@FreeBSD.org

RUN_DEPENDS=	cdrecord:${PORTSDIR}/sysutils/cdrecord \
		mkisofs:${PORTSDIR}/sysutils/mkisofs

USE_KDELIBS_VER=2
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

post-patch:
	@${PERL} -pi -e 's#lqt#lqt2#g' ${WRKSRC}/configure

.include <bsd.port.mk>
