# New ports collection makefile for:	koncd
# Date created:				2 April 2001
# Whom:					Dmitry Sivachenko <demon@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	koncd
PORTVERSION=	1.0r2
CATEGORIES=	sysutils kde
MASTER_SITES=	http://www.koncd.org/download/ \
		ftp://apps.kde.com/pub/Multimedia/Audio/Burners_Rippers/KOnCD/
DISTNAME=	${PORTNAME}-1.0rc2

MAINTAINER=	demon@FreeBSD.org

RUN_DEPENDS=	cdrecord:${PORTSDIR}/sysutils/cdrtools \
		mkisofs:${PORTSDIR}/sysutils/mkisofs \
		mpg123:${PORTSDIR}/audio/mpg123

USE_KDELIBS_VER=2
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

post-patch:
	@${PERL} -pi -e 's#lqt#lqt2#g' ${WRKSRC}/configure

.include <bsd.port.mk>
