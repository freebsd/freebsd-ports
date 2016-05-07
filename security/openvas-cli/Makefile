# $FreeBSD$

PORTNAME=	openvas-cli
PORTVERSION=	1.4.3
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://wald.intevation.org/frs/download.php/2209/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	OpenVAS command-line interface and Nagios plugin

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgnutls.so:security/gnutls \
		libopenvas_base.so:security/openvas-libraries

CFLAGS+=	-Wno-missing-field-initializers
USES=		cmake:outsource gnome pkgconfig
USE_GNOME=	glib20 libxslt:run

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/libexec/nagios
	${MV} ${STAGEDIR}${PREFIX}/bin/check_omp \
		${STAGEDIR}${PREFIX}/libexec/nagios

.include <bsd.port.mk>
