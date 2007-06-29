# New ports collection makefile for:   rapip
# Date created:                15 June 2003
# Whom:                        Sam Lawrance <boris@brooknet.com.au>
#
# $FreeBSD$

PORTNAME=	synce-kde
PORTVERSION=	0.9.1
PORTREVISION=	1
CATEGORIES=	palm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	synce

MAINTAINER=	araujo@FreeBSD.org
COMMENT=	SynCE KDE Utilities

LIB_DEPENDS+=	synce.0:${PORTSDIR}/palm/synce-libsynce \
		rapi.2:${PORTSDIR}/palm/synce-librapi2 \
		rra.0:${PORTSDIR}/palm/synce-rra \
		dynamite.0:${PORTSDIR}/archivers/dynamite \
		orange.0:${PORTSDIR}/archivers/orange \
		unshield.0:${PORTSDIR}/archivers/unshield

RUN_DEPENDS+=	synce-serial-start:${PORTSDIR}/palm/synce-serial

USE_KDELIBS_VER=3
USE_GMAKE=	yes
USE_ICONV=	yes
USE_AUTOTOOLS=	libtool:15
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	LDFLAGS="${PTHREAD_LIBS}"

INSTALLS_ICONS=	yes
USE_GETTEXT=	yes

PORTDOCS=	*
DOCSDIR=	${PREFIX}/share/doc/HTML/en/raki

post-install:
	${INSTALL} -c -o root -g wheel ${WRKSRC}/rapip/.libs/kio_rapip.lai ${PREFIX}/lib/kde3/kio_rapip.la

.include <bsd.port.mk>
