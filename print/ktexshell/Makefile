# New ports collection makefile for:	ktexshell
# Date created:				28 March 2001
# Whom:					Dmitry Sivachenko <demon@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ktexshell
PORTVERSION=	0.4.0
CATEGORIES=	print kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	ktexshell

MAINTAINER=	demon@FreeBSD.org

LIB_DEPENDS=	intl.1:${PORTSDIR}/devel/gettext

USE_KDELIBS_VER=2
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

post-patch:
	@${PERL} -pi -e 's#libqt#libqt2#g' ${WRKSRC}/configure
	@${PERL} -pi -e 's#lqt#lqt2#g' ${WRKSRC}/configure ${WRKSRC}/ktexshell/Makefile.in

.include <bsd.port.mk>
