PORTNAME=	spamfilter
PORTVERSION=	1.5.1r${REV}
PORTREVISION=	3
CATEGORIES=	www devel python
MASTER_SITES=	https://trac.edgewall.org/browser/plugins/trunk/spam-filter?rev=${REV}&format=zip&dummy=/
PKGNAMEPREFIX=	trac-

MAINTAINER=	samm@FreeBSD.org
COMMENT=	Trac Spam Filtering Plugin
WWW=		https://trac.edgewall.org/wiki/SpamFilter

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	tracd:www/trac

REV=			17911
WRKSRC=			${WRKDIR}/spam-filter
USES=			python zip
USE_PYTHON=		distutils autoplist
NO_ARCH=		yes

.include <bsd.port.mk>
