# New ports collection makefile for:	mahogany
# Date created:		11 November 2000
# Whom:			Stephen Kiernan <sk-ports@vegamuse.org>
#
# $FreeBSD$
#

PORTNAME=		mahogany
PORTVERSION=		0.65
PORTREVISION=		2
CATEGORIES=		mail
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	mahogany

MAINTAINER=		ports@FreeBSD.org
COMMENT=		An X11 mail and news client

LIB_DEPENDS+=		wx_gtk2-2.4.0:${PORTSDIR}/x11-toolkits/wxgtk2

USE_X_PREFIX=		yes
GNU_CONFIGURE=		yes
USE_GMAKE=		yes
USE_REINPLACE=		yes
ALL_TARGET=		all locales
INSTALL_TARGET=		install_bin install_locale

MAN1=			M.1 mahogany.1

CONFIGURE_ARGS=		--with-python=none \
			--with-wx-config=${X11BASE}/bin/wxgtk2-2.4-config
CONFIGURE_ENV=		OSTYPE=${OPSYS} CFLAGS="${CFLAGS}"

post-patch:
	@${REINPLACE_CMD} -e 's|-DOPENSSL_NO_KRB5||' -e 's|-O2|${CFLAGS}|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|$$(DATADIR)/locale|$$(DESTDIR)/share/locale|' ${WRKSRC}/locale/Makefile

.include <bsd.port.mk>
