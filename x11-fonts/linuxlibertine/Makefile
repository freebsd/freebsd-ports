# Created by: Björn König <bkoenig@alpha-tierchen.de>
# $FreeBSD$

PORTNAME=	linuxlibertine
PORTVERSION=	4.7.5
PORTREVISION=	4
CATEGORIES=	x11-fonts
MASTER_SITES=	SF
DISTNAME=	LinLibertineFont-${PORTVERSION}-2
EXTRACT_SUFX=	.tgz

MAINTAINER=	office@FreeBSD.org
COMMENT=	Linux Libertine Open Fonts

LICENSE=	GPLv2 LINUXLIBERTINE OFL10
LICENSE_COMB=	multi

USES=		fonts

OPTIONS_DEFINE=	DOCS

LICENSE_NAME_LINUXLIBERTINE=	LinuxLibertine License
LICENSE_FILE_LINUXLIBERTINE=	${WRKSRC}/LICENCE.txt
LICENSE_PERMS_LINUXLIBERTINE=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

LICENSE_NAME_OFL=	Open Fonts License
LICENSE_FILE_OFL=	${WRKSRC}/OFL.txt
LICENSE_PERMS_OFL=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

WRKSRC=		${WRKDIR}/LinLibertine
NO_BUILD=	yes

PORTDOCS=	Bugs.txt \
		ChangeLog.txt \
		Readme.txt \
		Readme-TEX.txt

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
.for ext in ttf otf
	${INSTALL_DATA} ${WRKSRC}/Fonts/*.${ext} ${STAGEDIR}${FONTSDIR}
.endfor
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/$i ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
