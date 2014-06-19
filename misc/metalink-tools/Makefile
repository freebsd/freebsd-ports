# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	metalink
PORTVERSION=	0.3.6
PORTREVISION=	3
CATEGORIES=	misc
MASTER_SITES=	SF/metalinks/Metalink%20commandline/${PORTVERSION}
PKGNAMESUFFIX?=	-tools

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Metalink generation tool

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgcrypt.so:${PORTSDIR}/security/libgcrypt \
		libglibmm-2.4.so:${PORTSDIR}/devel/glibmm \
		libgpg-error.so:${PORTSDIR}/security/libgpg-error \
		libsigc-2.0.so:${PORTSDIR}/devel/libsigc++20

USE_GNOME=	glib20
GNU_CONFIGURE=	yes
USES=		pkgconfig
CONFIGURE_ENV+=	AWK="${AWK}"
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PORTDOCS=	README
PLIST_FILES=	bin/${PORTNAME}

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
