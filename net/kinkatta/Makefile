# New ports collection makefile for:	kinkatta
# Date created:				1 November 2001
# Whom:					petef
#
# $FreeBSD$
#

PORTNAME=	kinkatta
PORTVERSION=	1.00
CATEGORIES=	net kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	kinkatta

MAINTAINER=	petef@FreeBSD.org

USE_KDELIBS_VER=	2
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	KDEDIR="${LOCALBASE}"

post-patch:
	@${PERL} -pi -e 's,-O2,,g' ${WRKSRC}/configure
	@${PERL} -pi -e 's,-lqt,-lqt2,; s,-lpthread,${PTHREAD_LIBS:S/"//g},' \
		${WRKSRC}/kinkatta/Makefile.in

.include <bsd.port.mk>
