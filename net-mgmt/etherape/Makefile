# Created by: Holger Lamm <holger@eit.uni-kl.de>
# $FreeBSD$

PORTNAME=	etherape
PORTVERSION=	0.9.14
CATEGORIES=	net-mgmt gnome
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Graphical network traffic monitor tool modeled after Etherman

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gettext gmake iconv pathfix pkgconfig
USE_GNOME=	gnomedocutils libglade2 libgnomeui
GNU_CONFIGURE=	yes
INSTALLS_OMF=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PORTDOCS=	AUTHORS ChangeLog FAQ NEWS README README.bugs TODO

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e \
		's|char \*argv)|char **argv)|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's|__EXPORT__|__EXPORT_H__|' ${WRKSRC}/src/export.h

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
