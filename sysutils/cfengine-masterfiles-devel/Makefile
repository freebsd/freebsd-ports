PORTNAME=	cfengine-masterfiles
PORTVERSION=	3.25.${CFENGINE_COMMIT_DATE}
PORTEPOCH=	1
CATEGORIES=	sysutils
PKGNAMESUFFIX=	-devel
HASH=		948f7800
CFENGINE_COMMIT_DATE=	20250619

MAINTAINER=	cy@FreeBSD.org
COMMENT=	cfengine sample policies for installations and upgrades
WWW=		https://cfengine.com/

LICENSE=	GPLv3

USE_GITHUB=	yes
GH_ACCOUNT=	cfengine
GH_PROJECT=	masterfiles
GH_TAGNAME=	${HASH}
CPE_VENDOR=	gnu
CPE_PRODUCT=	cfengine

CONFLICTS=	cfengine-masterfiles3[0-9]-* cfengine-masterfiles31[02-9]-* \
		cfengine-masterfiles-3.*

RUN_DEPENDS=	cf-agent:sysutils/cfengine${PKGNAMESUFFIX}

FETCH_BEFORE_ARGS=	-o ${DISTDIR}/${DISTFILES}

MAKE_JOBS_UNSAFE=	yes
USES=		autoreconf:build cpe gmake python:build
HAS_CONFIGURE=	yes
EXAMPLESDIR=	${PREFIX}/share/examples/cfengine-masterfiles
CONFIGURE_SCRIPT=	./autogen.sh
CONFIGURE_ARGS=	--prefix=${EXAMPLESDIR}
CONFIGURE_ENV=	EXPLICIT_VERSION=${PORTVERSION}-${HASH}

.include <bsd.port.mk>
