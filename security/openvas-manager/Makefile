# $FreeBSD$

PORTNAME=	openvas-manager
PORTVERSION=	6.0.8
CATEGORIES=	security
MASTER_SITES=	http://wald.intevation.org/frs/download.php/2295/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	OpenVAS manager

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgnutls.so:${PORTSDIR}/security/gnutls \
		libgpgme.so:${PORTSDIR}/security/gpgme \
		libgcrypt.so:${PORTSDIR}/security/libgcrypt \
		libopenvas_base.so:${PORTSDIR}/security/openvas-libraries

USES=		cmake:outsource execinfo gnome pkgconfig sqlite
USE_GNOME=	glib20
USE_RC_SUBR=	openvasmd

OPTIONS_DEFINE=	DOCS

post-install:
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
