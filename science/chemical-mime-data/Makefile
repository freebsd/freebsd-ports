PORTNAME=	chemical-mime-data
PORTVERSION=	0.1.94
PORTREVISION=	12
CATEGORIES=	science
MAINTAINER=	ports@FreeBSD.org
COMMENT=	Collection of chemical MIME types for UNIX desktops
WWW=		https://github.com/dleidert/chemical-mime

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf gettext-tools gmake gnome localbase:ldflags pathfix pkgconfig \
		shared-mime-info  tar:bzip2
USE_GNOME=	gnomemimedata intlhack librsvg2:build libxslt:build
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-update-database \
		--without-kde-magic

USE_GITHUB=	yes
GH_ACCOUNT=	dleidert
GH_PROJECT=	chemical-mime
GH_TAGNAME=	4fd66e3b3b7d922555d1e25587908b036805c45b

post-patch:
	@${REINPLACE_CMD} -e 's:acronym|alias|comment|:acronym|alias|comment|generic-icon|:' \
		${WRKSRC}/xsl/cmd_freedesktop_org.xsl

.include <bsd.port.mk>
