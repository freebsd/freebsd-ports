# New ports collection makefile for:	edonkey gtk gui link submitter
# Date created:			Sat Feb 23 13:13:08 BRT 2002
# Whom:		Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	edonkey
PORTVERSION=	0.0.1
PORTREVISION=	1
CATEGORIES=	net kde
MASTER_SITES=	http://users.aber.ac.uk/tpm01/ \
		http://krazykiwi.homeip.net/admin/:kde_admin \
		${MASTER_SITE_LOCAL:S/$/:kde_admin/}
MASTER_SITE_SUBDIR=	lioux/:kde_admin
PKGNAMESUFFIX=	-gui-gtk-kioslave
DISTFILES=	ed2k_kde2_kioslave.tar.gz \
		kde-admindir-3.0.1.tar.gz:kde_admin

MAINTAINER=	lioux@FreeBSD.org

RUN_DEPENDS=	ed2k_gui:${PORTSDIR}/net/edonkey-gui-gtk

USE_AUTOMAKE_VER=	15
USE_KDELIBS_VER=	3
USE_XLIB=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/ed2kslave

post-extract:
	@${RM} -Rf ${WRKSRC}/admin
	@${CP} -Rp ${WRKDIR}/admin ${WRKSRC}

pre-configure:
	@${RM} -f ${WRKSRC}/config.cache
	@cd ${WRKSRC} && ${GMAKE} -f admin/Makefile.common cvs || ${TRUE}

.include <bsd.port.mk>
