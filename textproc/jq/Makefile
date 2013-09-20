# Created by: Jui-Nan Lin <jnlin@csie.nctu.edu.tw>
# $FreeBSD$

PORTNAME=	jq
PORTVERSION=	1.1
CATEGORIES=	textproc

MAINTAINER=	jnlin@csie.nctu.edu.tw
COMMENT=	Lightweight and flexible command-line JSON processor

USE_GITHUB=	yes
GH_ACCOUNT=	stedolan
GH_TAGNAME=	jq-${PORTVERSION}
GH_COMMIT=	bf61e95

USE_GMAKE=	yes
USE_CSTD=	gnu99

PLIST_FILES=	bin/jq

NO_STAGE=	yes
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/jq ${PREFIX}/bin

.include <bsd.port.mk>
