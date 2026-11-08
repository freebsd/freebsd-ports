PORTNAME=	enchant2
PORTVERSION=	2.2.15
DISTVERSIONSUFFIX=	-6.el9
CATEGORIES=	textproc linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Dictionary/spellchecking library (Rocky Linux ${LINUX_DIST_VER})
WWW=		https://abiword.github.io/enchant/

LICENSE=	LGPL21+

USES=		linux:rl9
USE_LDCONFIG=	yes
USE_LINUX_RPM=	yes
WANT_LINUX32=	yes

DESCR=		${PORTSDIR}/${PKGCATEGORY}/${PORTNAME}/pkg-descr
DOCSDIR=	${PREFIX}/usr/share/doc/${PORTNAME}

OPTIONS_DEFINE=	DOCS
OPTIONS_SUB=	yes

.include <bsd.port.mk>
