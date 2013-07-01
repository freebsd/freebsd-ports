# Created by: sahne
# $FreeBSD$

PORTNAME=	lxde-common
PORTVERSION=	0.5.5
PORTREVISION=	4
CATEGORIES=	misc
MASTER_SITES=	SF/lxde/${PORTNAME}%20%28default%20config%29/LXDE%20Common%20${PORTVERSION}/

MAINTAINER=	nemysis@gmx.ch
COMMENT=	LXDE Common files

LICENSE=	GPLv2

USES=		iconv
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		GMSGFMT="${LOCALBASE}/bin/msgfmt" \
		--with-xsession-path=${PREFIX}/share/xsessions \
		--with-xdg-path=${PREFIX}/share/applications
USE_GMAKE=	yes

DATADIR=	${PREFIX}/share/lxde
INSTALLS_ICONS=	YES

MAN1=		startlxde.1 lxde-logout.1 openbox-lxde.1

PORTDOCS=	AUTHORS README

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-install:
	${INSTALL_DATA} ${WRKSRC}/desktop.conf ${PREFIX}/etc/xdg/lxsession/LXDE/desktop.conf.sample
	${INSTALL_DATA} ${WRKSRC}/pcmanfm/pcmanfm.conf ${PREFIX}/etc/xdg/pcmanfm/LXDE/pcmanfm.conf.sample
	@[ -f ${PREFIX}/etc/xdg/lxsession/LXDE/desktop.conf ] || \
		${INSTALL_DATA} ${WRKSRC}/desktop.conf ${PREFIX}/etc/xdg/lxsession/LXDE/desktop.conf
	@[ -f ${PREFIX}/etc/xdg/pcmanfm/LXDE/pcmanfm.conf ] || \
		${INSTALL_DATA} ${WRKSRC}/pcmanfm/pcmanfm.conf ${PREFIX}/etc/xdg/pcmanfm/LXDE/pcmanfm.conf

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
