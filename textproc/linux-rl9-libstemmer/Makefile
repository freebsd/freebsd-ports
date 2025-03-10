PORTNAME=	libstemmer
PORTVERSION=	0
DISTVERSIONSUFFIX=	-18.585svn.el9
CATEGORIES=	textproc linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	C stemming algorithm library (Rocky Linux ${LINUX_DIST_VER})
WWW=		http://snowball.tartarus.org

LICENSE=	BSD3CLAUSE

USES=		cpe linux:rl9
USE_LDCONFIG=	yes
USE_LINUX_RPM=	yes
WANT_LINUX32=	yes

OPTIONS_DEFINE=	DOCS

DOCSDIR=	${PREFIX}/usr/share/doc/${PORTNAME}${PKGNAMESUFFIX}

.include <bsd.port.mk>
