# Created by: cy@FreeBSD.org
# $FreeBSD$

PORTNAME=	cfengine-masterfiles
PORTVERSION=	3.${CFENGINE_COMMIT_DATE}
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	https://cfengine-package-repos.s3.amazonaws.com/tarballs/
PKGNAMESUFFIX=	-devel
HASH=		1d8633d
CFENGINE_COMMIT_DATE=	2019.02.19

MAINTAINER=	cy@FreeBSD.org
#		gjb@FreeBSD.org is also committer for this port
#		skreuzer@FreeBSD.org is also committer for this port
COMMENT=	cfengine sample policies for installations and upgrades

LICENSE=	GPLv3

USE_GITHUB=     yes
GH_ACCOUNT=	cfengine
GH_PROJECT=     masterfiles
GH_TAGNAME=     ${HASH}
CPE_VENDOR=	gnu

CONFLICTS=	cfengine-masterfiles3[0-9]-* cfengine-masterfiles31[02-9]-* \
		cfengine-masterfiles-3.*

RUN_DEPENDS=	cf-agent:sysutils/cfengine${PKGNAMESUFFIX}

FETCH_BEFORE_ARGS=	-o ${DISTDIR}/${DISTFILES}

MAKE_JOBS_UNSAFE=	yes
USES=		autoreconf:build cpe gmake python:build shebangfix
HAS_CONFIGURE=	yes
EXAMPLESDIR=	${PREFIX}/share/examples/cfengine-masterfiles
CONFIGURE_SCRIPT=	./autogen.sh
CONFIGURE_ARGS=	--prefix=${EXAMPLESDIR}
CONFIGURE_ENV=	EXPLICIT_VERSION=${PORTVERSION}-${HASH}
SHEBANG_FILES=	modules/packages/yum  modules/packages/zypper

.include <bsd.port.mk>
