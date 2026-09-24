PORTNAME=	hyphen
PORTVERSION=	2.8.8
DISTVERSIONSUFFIX=	-17.el9
CATEGORIES=	textproc linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Text hyphenation library (Rocky Linux ${LINUX_DIST_VER})
WWW=		https://github.com/hunspell/hyphen

LICENSE=	GPLv2 LGPL21+ MPL11
LICENSE_COMB=	dual

USES=		linux:rl9
USE_LDCONFIG=	yes
USE_LINUX_RPM=	yes
WANT_LINUX32=	yes

DESCR=		${PORTSDIR}/${PKGCATEGORY}/${PORTNAME}/pkg-descr
DOCSDIR=	${PREFIX}/usr/share/doc/${PORTNAME}

OPTIONS_DEFINE=	DOCS
OPTIONS_SUB=	yes

.include <bsd.port.mk>
