# New ports collection makefile for:   ksamba
# Date created:        18 May 1998
# Whom:                Hans Petter Bieker <hanspb@persbraten.vgs.no>
#
# $FreeBSD$
#

PORTNAME=	ksamba
PORTVERSION=	0.3.4
CATEGORIES=	net kde
MASTER_SITES=	${MASTER_SITE_KDE} \
		http://www.kneschke.de/projekte/ksamba/download/
MASTER_SITE_SUBDIR=	unstable/apps/network

BUILD_DEPENDS=	msgfmt:${PORTSDIR}/devel/gettext

USE_KDELIBS_VER=1
USE_GMAKE=	yes
USE_AUTOMAKE=	yes
CONFIGURE_ENV=	QTDIR="${X11BASE}" KDEDIR="${LOCALBASE}" \
		MOC="${X11BASE}/bin/moc"
CONFIGURE_ARGS=	--with-qt-includes=${X11BASE}/include/X11/qt

post-extract:
	@${RM} -f ${WRKSRC}/config.cache
	@${RM} -f ${WRKSRC}/ksamba/*.moc

post-patch:
	@cd ${WRKSRC} && aclocal

.include <bsd.port.mk>
