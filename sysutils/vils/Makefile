# Created by: Jeffrey H. Johnson <CPE1704TKS@bellsouth.net>
# $FreeBSD$

PORTNAME=	vils
PORTVERSION=	20020228
CATEGORIES=	sysutils
MASTER_SITES=	http://www.secnetix.de/~olli/scripts/
DISTFILES=	vils

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Use your favorite editor to rename files

BUILD_DEPENDS=	zsh:${PORTSDIR}/shells/zsh
RUN_DEPENDS:=	${BUILD_DEPENDS}

PLIST_FILES=	bin/${PORTNAME}

do-extract:
	${MKDIR} ${WRKDIR}
	${CP} ${DISTDIR}/vils ${WRKDIR}/vils

do-build:
	@${REINPLACE_CMD} -e 's/\/bin\/zsh/\/usr\/local\/bin\/zsh/' ${WRKDIR}/vils

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/vils ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
