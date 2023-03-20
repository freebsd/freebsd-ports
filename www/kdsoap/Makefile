PORTNAME=	kdsoap
DISTVERSION=	2.1.1
CATEGORIES=	www
# It's on GitHub, but KDAB uploads tidy release tarballs,
# so do NOT USE_GITHUB, but do write out the variables.
MASTER_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/releases/download/${PORTNAME}-${DISTVERSION}/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	C++/Qt SOAP framework
WWW=		https://github.com/KDAB/KDSoap

# The software is partly under (LGPL21 | GPL2 | GPL3 ), and partly
# under AGPLv3. We choose LGPL21 and AGPLv3, since that's easiest
# to express in a ports Makefile.
LICENSE=	LGPL21 AGPLv3
LICENSE_COMB=	multi

USES=		cmake compiler:c++11-lang localbase pkgconfig qt:5
USE_LDCONFIG=	yes
USE_QT=		core network widgets xml \
		buildtools:build linguisttools:build qmake:build

# No USE_GITHUB, but pretty close
GH_ACCOUNT=	KDAB
GH_PROJECT=	KDSoap

PLIST_SUB=	SOVER=${DISTVERSION}

.include <bsd.port.mk>
