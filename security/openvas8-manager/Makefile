# $FreeBSD$

PORTNAME=	openvas-manager
PORTVERSION=	6.0.8
PORTREVISION=	5
CATEGORIES=	security
MASTER_SITES=	http://wald.intevation.org/frs/download.php/2295/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	OpenVAS manager

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgnutls.so:security/gnutls \
		libgpgme.so:security/gpgme \
		libgcrypt.so:security/libgcrypt \
		libopenvas_base.so:security/openvas-libraries

USES=		cmake:outsource execinfo gnome pkgconfig sqlite
USE_GNOME=	glib20
USE_RC_SUBR=	openvasmd
REINPLACE_ARGS=	-i ''

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e '1d' ${WRKSRC}/tools/extra/xml_split

post-install:
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
