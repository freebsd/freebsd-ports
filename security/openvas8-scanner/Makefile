# Created by: Tomoyuki Sakurai <cherry@trombik.org>
# $FreeBSD$

PORTNAME=	openvas-scanner
PORTVERSION=	5.0.5
CATEGORIES=	security
MASTER_SITES=	http://wald.intevation.org/frs/download.php/2266/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	OpenVAS scanner

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING.GPLv2

LIB_DEPENDS=	libgcrypt.so:security/libgcrypt \
		libopenvas_base.so:security/openvas-libraries
RUN_DEPENDS=	redis-server:databases/redis \
		curl:ftp/curl \
		rsync:net/rsync

USES=		cmake:outsource execinfo gettext-runtime gnome pkgconfig
USE_GNOME=	glib20
USE_RC_SUBR=	openvassd

OPTIONS_DEFINE=	DOCS

post-install:
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
