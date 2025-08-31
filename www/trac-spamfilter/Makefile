PORTNAME=	spamfilter
PORTVERSION=	1.5.1r${REV}
PORTREVISION=	2
CATEGORIES=	www devel python
MASTER_SITES=	https://trac.edgewall.org/browser/plugins/trunk/
PKGNAMEPREFIX=	trac-

MAINTAINER=	samm@FreeBSD.org
COMMENT=	Trac Spam Filtering Plugin
WWW=		https://trac.edgewall.org/wiki/SpamFilter

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	tracd:www/trac

FETCH_BEFORE_ARGS=	-o ${DISTFILES}
REV=			17824
WRKSRC=			${WRKDIR}/spam-filter
USES=			python zip
USE_PYTHON=		distutils autoplist
NO_ARCH=		yes

do-fetch:
	@if [ ! -f ${DISTDIR}/${DISTFILES} ]; then \
	cd ${DISTDIR} && \
	${FETCH_CMD} ${FETCH_BEFORE_ARGS}	\
		'${MASTER_SITES}spam-filter?rev=${REV}&format=zip'; \
	fi

.include <bsd.port.mk>
