# New ports collection makefile for:   lxde-common
# Date created:                2009/02/03
# Whom:                        sahne
#
# $FreeBSD$
#

PORTNAME=	lxde-common
PORTVERSION=	0.5.5
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	SF/lxde/${PORTNAME}%20%28default%20config%29/LXDE%20Common%20${PORTVERSION}

MAINTAINER=	kmoore@FreeBSD.org
COMMENT=	LXDE Common files

USE_GNOME=	gtk20
USE_GMAKE=	yes
USE_ICONV=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		GMSGFMT="${LOCALBASE}/bin/msgfmt" \
		--with-xsession-path=${PREFIX}/share/xsessions

DATADIR=	${PREFIX}/share/lxde
INSTALLS_ICONS=	YES

MAN1=	startlxde.1\
	lxde-logout.1 \
	openbox-lxde.1

.include <bsd.port.mk>
