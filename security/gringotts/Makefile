# Created by: Anders Nordby <anders@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gringotts
PORTVERSION=	1.2.10
PORTREVISION=	4
CATEGORIES=	security
MASTER_SITES=	BERLIOS

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK application to securely store sensitive data

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpopt.so:devel/popt \
		libgringotts.so:security/libgringotts

USES=		gettext gnome localbase pkgconfig
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e \
		'/^install-data-am:/s|install-DsktpDATA|| ; \
		 /^install-data-am:/s|install-docDATA|| ; \
		 s|@md5sum|@md5|' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e \
		'/^install-exec-am:/s|install-exec-local||' ${WRKSRC}/src/Makefile.in

post-install:
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.desktop ${STAGEDIR}${PREFIX}/share/applications

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in AUTHORS BUGS ChangeLog FAQ NEWS README TODO
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
