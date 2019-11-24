# Created by: Aldis Berjoza <aldis@bsdroot.lv>
# $FreeBSD$

PORTNAME=	htpasswd
PORTVERSION=	2019.10.15
CATEGORIES=	security python
MASTER_SITES=	https://svn.apache.org/repos/asf/bloodhound/trunk/trac/contrib/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}.py
EXTRACT_SUFX=	# empty

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Replacement for htpasswd

USES=		python shebangfix
SHEBANG_FILES=	${PORTNAME}.py

NO_ARCH=	yes

NO_WRKSUBDIR=	yes
EXTRACT_CMD=	${CP}
EXTRACT_AFTER_ARGS=	${WRKSRC}
EXTRACT_BEFORE_ARGS=	# empty

NO_BUILD=	yes
PLIST_FILES=	bin/${PORTNAME}.py

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.py ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
