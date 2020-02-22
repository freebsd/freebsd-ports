# $FreeBSD$

PORTNAME=	kdsoap
DISTVERSION=	1.9.0
CATEGORIES=	www
# It's on GitHub, but KDAB uploads tidy release tarballs,
# so do NOT USE_GITHUB, but do write out the variables.
MASTER_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/releases/download/${PORTNAME}-${DISTVERSION}/

MAINTAINER=	adridg@FreeBSD.org
COMMENT=	C++/Qt SOAP framework

# The software is partly under (LGPL21 | GPL2 | GPL3 ), and partly
# under AGPLv3. We choose LGPL21 and AGPLv3, since that's easiest
# to express in a ports Makefile.
LICENSE=	LGPL21 AGPLv3
LICENSE_COMB=	multi
LICENSE_FILE_LGPL21=	${WRKSRC}/LICENSE.LGPL.txt
LICENSE_FILE_AGPLv3=	${WRKSRC}/LICENSE.AGPL3-modified.txt

USES=		cmake compiler:c++11-lang localbase qt:5
USE_LDCONFIG=	yes
USE_QT=		qmake_build buildtools_build linguisttools_build \
		core network widgets xml

# No USE_GITHUB, but pretty close
GH_ACCOUNT=	KDAB
GH_PROJECT=	KDSoap

PLIST_SUB=	SOVER=${DISTVERSION}

.include <bsd.port.mk>
