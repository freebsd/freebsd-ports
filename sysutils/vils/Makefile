# Created by: Jeffrey H. Johnson <CPE1704TKS@bellsouth.net>
# $FreeBSD$

PORTNAME=	vils
PORTVERSION=	20020228
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.secnetix.de/~olli/scripts/Generic-utilities/
DISTFILES=	vils

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Use your favorite editor to rename files

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	zsh:shells/zsh

NO_BUILD=	yes
NO_ARCH=	yes
NO_WRKSUBDIR=	yes

EXTRACT_CMD=	${CP}
EXTRACT_BEFORE_ARGS=	-f
EXTRACT_AFTER_ARGS=	${WRKSRC}

USES=		shebangfix
SHEBANG_FILES=	vils
SHEBANG_LANG=	zsh
zsh_OLD_CMD=	/bin/zsh
zsh_CMD=	${LOCALBASE}/bin/zsh

PLIST_FILES=	bin/${PORTNAME}

do-install:
	(cd ${WRKSRC} && ${INSTALL_SCRIPT} vils ${STAGEDIR}${PREFIX}/bin)

.include <bsd.port.mk>
