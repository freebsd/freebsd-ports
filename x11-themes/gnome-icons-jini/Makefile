# $FreeBSD$

PORTNAME=	jini
PORTVERSION=	0.8
CATEGORIES=	x11-themes gnome
MASTER_SITES=	http://kldp.net/frs/download.php/3799/
PKGNAMEPREFIX=	gnome-icons-
DISTNAME=	jini-icon-theme-${PORTVERSION}

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Jini Icons for Gnome

BROKEN=		unfetchable

USES=		gnome
INSTALLS_ICONS=	yes

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

post-extract:
	@for FILE in ${WRKSRC}/JiniOrange/scalable/apps/haansoft-hwp.svg \
		${WRKSRC}/JiniYellowishGreen/scalable/apps/haansoft-hwp.svg \
		${WRKSRC}/JiniBrown/scalable/apps/haansoft-hwp.svg \
		${WRKSRC}/JiniOrange/scalable/apps/haansoft-hwp.svg \
		${WRKSRC}/JiniYellowishGreen/scalable/apps/haansoft-hwp.svg; do \
		${LN} -sf ../../../JiniBlueSky/scalable/apps/haansoft-hwp.svg $${FILE}; \
	done

do-install:
	cd ${WRKSRC} && ${FIND} Jini* | ${CPIO} -pdu ${STAGEDIR}${PREFIX}/share/icons

.include <bsd.port.mk>
