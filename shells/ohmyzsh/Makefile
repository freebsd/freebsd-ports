# Created by: Serhii (Sergey) Kozlov <skozlov@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ohmyzsh
PORTVERSION=	20200722
CATEGORIES=	shells

MAINTAINER=	skozlov@FreeBSD.org
COMMENT=	Community-driven framework for managing your zsh configuration

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	zsh:shells/zsh

USE_GITHUB=	yes
GH_TAGNAME=	db3d05f

NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES=	pkg-message

post-extract:
	${RM} -r ${WRKSRC}/log ${WRKSRC}/cache
.for f in install upgrade uninstall check_for_upgrade
	${RM} ${WRKSRC}/tools/${f}.sh
.endfor

post-patch:
	${REINPLACE_CMD} -e "s|%%DATADIR%%|${DATADIR}|g" ${WRKSRC}/templates/zshrc.zsh-template

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR} "! -path \./\.* ! -name *\.bak ! -name *\.orig"

.include <bsd.port.mk>
