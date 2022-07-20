PORTNAME=	clearlooks-metacity
PORTVERSION=	2.0
PORTREVISION=	7
CATEGORIES=	x11-themes
MASTER_SITES=	http://www.stellingwerff.com/
#MASTER_SITES=	SOURCEFORGE/clearlooks

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Clearlooks Metacity theme

USES=		gnome

CONFLICTS=	gnome-themes-2.11.9[1-9]* gnome-themes-2.*

WRKSRC=		${WRKDIR}/Clearlooks/metacity-1/
USE_GNOME=	metacity gnomeprefix
DATADIR=	share/themes/Clearlooks/metacity-1
NO_BUILD=	yes

PLIST_FILES=	%%DATADIR%%/metacity-theme-1.xml

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/metacity-theme-1.xml ${STAGEDIR}${PREFIX}/${DATADIR}

.include <bsd.port.mk>
