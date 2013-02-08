# $FreeBSD$

PORTNAME=	jini
PORTVERSION=	0.8
CATEGORIES=	x11-themes gnome
MASTER_SITES=	http://kldp.net/frs/download.php/3799/
PKGNAMEPREFIX=	gnome-icons-
DISTNAME=	jini-icon-theme-${PORTVERSION}

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Jini Icons for Gnome

NO_BUILD=	yes
WRKSRC=		${WRKDIR}
WANT_GNOME=	yes
INSTALLS_ICONS=	yes

post-extract:
	@for FILE in ${WRKDIR}/JiniOrange/scalable/apps/haansoft-hwp.svg \
		${WRKDIR}/JiniYellowishGreen/scalable/apps/haansoft-hwp.svg \
		${WRKDIR}/JiniBrown/scalable/apps/haansoft-hwp.svg \
		${WRKDIR}/JiniOrange/scalable/apps/haansoft-hwp.svg \
		${WRKDIR}/JiniYellowishGreen/scalable/apps/haansoft-hwp.svg; do \
		${LN} -sf ../../../JiniBlueSky/scalable/apps/haansoft-hwp.svg $${FILE}; \
	done

do-install:
	@cd ${WRKDIR} && ${FIND} Jini* | ${CPIO} -pdu ${PREFIX}/share/icons

.include <bsd.port.mk>
