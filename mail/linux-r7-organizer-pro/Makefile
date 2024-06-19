PORTNAME=	r7-organizer-pro
PORTVERSION=	2.6.7
DISTVERSIONSUFFIX=	-1
CATEGORIES=	mail linux russian
MASTER_SITES=	https://download.r7-office.ru/organizer/centos/
PKGNAMEPREFIX=	linux-
DISTNAME=	r7organizer_pro-${PORTVERSION}${DISTVERSIONSUFFIX}
EXTRACT_SUFX=	.x86_64.rpm

MAINTAINER=	fluffy@FreeBSD.org
COMMENT=	Russian office mail, tasks and contacts organizer
WWW=		https://r7-office.ru/organizer

LICENSE=	commercial
LICENSE_NAME=	commercial
LICENSE_TEXT=	Commercial software with 30 days trial period
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

ONLY_FOR_ARCHS=	amd64

USES=		desktop-file-utils linux:rl9 shared-mime-info

USE_LINUX=	gtk3 sqlite3 alsalib

CONFLICTS_INSTALL=	linux-r7-organizer

NO_BUILD=	yes
PLIST_SUB=	LINUXBASE=${LINUXBASE}
STRIP=

post-patch:
	${REINPLACE_CMD} -i '' 's|/opt/r7-office/organizer/|${PREFIX}/bin/|' ${WRKDIR}/opt/r7-office/organizer/r7-organizer.desktop
	${REINPLACE_CMD} -i '' 's|P7|Р7|' ${WRKDIR}/opt/r7-office/organizer/r7-organizer.desktop

do-install:
	cd ${WRKDIR}/opt && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/share
	${RM} ${STAGEDIR}${PREFIX}/share/r7-office/organizer/r7organizer
	${INSTALL_PROGRAM} -C ${WRKDIR}/opt/r7-office/organizer/r7organizer ${STAGEDIR}${PREFIX}/share/r7-office/organizer/r7organizer
	${RLN} ${STAGEDIR}${PREFIX}/share/r7-office/organizer/r7organizer ${STAGEDIR}${PREFIX}/bin/
	${MV} ${STAGEDIR}${PREFIX}/share/r7-office/organizer/r7-organizer.desktop ${STAGEDIR}${PREFIX}/share/applications
	${RLN} ${STAGEDIR}${PREFIX}/share/r7-office/organizer/chrome/icons/default/default256.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/r7-organizer.png

.include <bsd.port.mk>
