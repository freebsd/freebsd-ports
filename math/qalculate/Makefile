# New ports collection makefile for:   qalculate
# Date created:        07 July 2004
# Whom:                Sergey Akifyev <asa@gascom.ru>
#
# $FreeBSD$
#

PORTNAME=	qalculate
PORTVERSION=	0.9.6
PORTREVISION=	3
CATEGORIES=	math
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-gtk/${PORTNAME}-gtk-${PORTVERSION}
DISTNAME=	${PORTNAME}-gtk-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A multi-purpose desktop calculator (Gnome frontend)

LIB_DEPENDS=	qalculate.4:${PORTSDIR}/math/libqalculate
RUN_DEPENDS=	gnuplot:${PORTSDIR}/math/gnuplot \
		wget:${PORTSDIR}/ftp/wget

USE_GNOME=	gnomehack gnomeprefix gnometarget intlhack libglade2 libgnome
USE_GETTEXT=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
INSTALLS_OMF=	yes

post-patch:
	@${REINPLACE_CMD} -e 's/^GMSGFMT = @GMSGFMT@/GMSGFMT = msgfmt/' ${WRKSRC}/po/Makefile.in.in

.include <bsd.port.mk>
