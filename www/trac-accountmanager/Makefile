PORTNAME=	accountmanager
PORTVERSION=	0.6.${REV}
PORTREVISION=	2
CATEGORIES=	www devel python
MASTER_SITES=	https://trac-hacks.org/browser/accountmanagerplugin/
PKGNAMEPREFIX=	trac-

MAINTAINER=	samm@FreeBSD.org
COMMENT=	Account Manager Plugin for trac
WWW=		https://trac-hacks.org/wiki/AccountManagerPlugin

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	tracd:www/trac

FETCH_BEFORE_ARGS=	-o ${DISTFILES}
REV=			18634
WRKSRC=			${WRKDIR}/trunk
USES=			python zip
USE_PYTHON=		distutils autoplist
NO_ARCH=		yes

do-fetch:
	@if [ ! -f ${DISTDIR}/${DISTFILES} ]; then \
	cd ${DISTDIR} && \
	${FETCH_CMD} ${FETCH_BEFORE_ARGS}	\
		'${MASTER_SITES}trunk?rev=${REV}&format=zip'; \
	fi

.include <bsd.port.mk>
