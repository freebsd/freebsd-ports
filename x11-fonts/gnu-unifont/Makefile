# Created by: nrg milk <bsdports@gmail.com>
# $FreeBSD$

PORTNAME=	gnu-unifont
PORTVERSION=	20140214
CATEGORIES=	x11-fonts
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=unifont/unifont-6.3.${PORTVERSION}
DISTNAME=	unifont-6.3.${PORTVERSION}.pcf
EXTRACT_SUFX=	.gz
EXTRACT_ONLY=

MAINTAINER=	bsdports@gmail.com
COMMENT=	Unicode Font

BUILD_DEPENDS=	mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir
RUN_DEPENDS=	mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir

NO_BUILD=	yes
PLIST_FILES=	"@unexec mkfontdir %D/lib/X11/fonts/local 2>/dev/null || true" \
		lib/X11/fonts/local/unifont.pcf.gz	\
		"@exec mkfontdir %D/lib/X11/fonts/local 2>/dev/null || true"

do-install:
	${INSTALL_DATA} ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} \
		${STAGEDIR}${PREFIX}/lib/X11/fonts/local/unifont.pcf.gz

.include <bsd.port.mk>
