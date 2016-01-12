# Created by: Jim Mock <jimFreeBSD.org>
# $FreeBSD$

PORTNAME=	erwn
PORTVERSION=	0.8
PORTREVISION=	12
CATEGORIES=	www editors
MASTER_SITES=	https://lisas.de/erwin/
DISTNAME=	erwin-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple GTK+-2 HTML editor

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		pathfix pkgconfig gmake
USE_GNOME=	gnomeprefix gtksourceview gtkhtml3
GNU_CONFIGURE=	yes

OPTIONS_DEFINE= DOCS

post-patch:
	@${REINPLACE_CMD} -e "s|gtkhtml-3.6|gtkhtml-3.14|g" \
		${WRKSRC}/configure

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
