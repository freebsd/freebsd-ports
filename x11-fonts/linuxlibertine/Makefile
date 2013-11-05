# Created by: Björn König <bkoenig@alpha-tierchen.de>
# $FreeBSD$

PORTNAME=	linuxlibertine
PORTVERSION=	4.7.5
CATEGORIES=	x11-fonts
MASTER_SITES=	SF
DISTNAME=	LinLibertineFont-${PORTVERSION}-2
EXTRACT_SUFX=	.tgz

MAINTAINER=	bkoenig@alpha-tierchen.de
COMMENT=	Linux Libertine Open Fonts

LICENSE=	GPLv2 LINUXLIBERTINE OFL10
LICENSE_COMB=	multi

BUILD_DEPENDS=	fc-cache:${PORTSDIR}/x11-fonts/fontconfig
RUN_DEPENDS=	fc-cache:${PORTSDIR}/x11-fonts/fontconfig

LICENSE_NAME_LINUXLIBERTINE=	LinuxLibertine License
LICENSE_FILE_LINUXLIBERTINE=	${WRKSRC}/LICENCE.txt
LICENSE_PERMS_LINUXLIBERTINE=	auto-accept

LICENSE_NAME_OFL=	Open Fonts License
LICENSE_FILE_OFL=	${WRKSRC}/OFL.txt
LICENSE_PERMS_OFL=	auto-accept

SUB_FILES=	pkg-deinstall
SUB_LIST=	FONTSDIR=${FONTSDIR}
WRKSRC=		${WRKDIR}/LinLibertine
FONTSDIR?=	${PREFIX}/lib/X11/fonts/${PORTNAME}
PLIST_SUB=	FONTSDIR="${FONTSDIR:S|${PREFIX}/||}"
NO_BUILD=	yes

PORTDOCS=	Bugs.txt \
		ChangeLog.txt \
		Readme.txt \
		Readme-TEX.txt

NO_STAGE=	yes
do-install:
	${MKDIR} ${FONTSDIR}
.for ext in ttf otf
	${INSTALL_DATA} ${WRKSRC}/Fonts/*.${ext} ${FONTSDIR}
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/$i ${DOCSDIR}
.endfor
.endif

post-install:
	@${ECHO_MSG} "===> Running fc-cache"
	-${LOCALBASE}/bin/fc-cache -f -v ${FONTSDIR}

.include <bsd.port.mk>
