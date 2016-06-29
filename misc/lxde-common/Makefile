# Created by: sahne
# $FreeBSD$

PORTNAME=	lxde-common
PORTVERSION=	0.5.5
PORTREVISION=	5
CATEGORIES=	misc
MASTER_SITES=	SF/lxde/${PORTNAME}%20%28default%20config%29/LXDE%20Common%20${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	LXDE Common files

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake iconv
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		GMSGFMT="${LOCALBASE}/bin/msgfmt" \
		--with-xsession-path=${PREFIX}/share/xsessions \
		--with-xdg-path=${PREFIX}/share/applications
NO_ARCH=	yes

DATADIR=	${PREFIX}/share/lxde
INSTALLS_ICONS=	yes

PORTDOCS=	AUTHORS README

OPTIONS_DEFINE=	DOCS

post-install:
	${INSTALL_DATA} ${WRKSRC}/desktop.conf \
		${STAGEDIR}${PREFIX}/etc/xdg/lxsession/LXDE/desktop.conf.sample
	${INSTALL_DATA} ${WRKSRC}/pcmanfm/pcmanfm.conf \
		${STAGEDIR}${PREFIX}/etc/xdg/pcmanfm/LXDE/pcmanfm.conf.sample

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
