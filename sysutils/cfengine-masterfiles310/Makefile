# Created by: cy@FreeBSD.org
# $FreeBSD$

PORTNAME=	cfengine-masterfiles
PORTVERSION=	3.10.3
CATEGORIES=	sysutils
MASTER_SITES=	https://cfengine-package-repos.s3.amazonaws.com/tarballs/

MAINTAINER=	cy@FreeBSD.org
#		gjb@FreeBSD.org is also committer for this port
#		skreuzer@FreeBSD.org is also committer for this port
COMMENT=	cfengine sample policies for installations and upgrades

LICENSE=	GPLv3

DEPRECATED=		cfengine310 will retire at FreeBSD 11 EOL
EXPIRATION_DATE=	2021-09-30

CPE_VENDOR=	gnu

CONFLICTS=	cfengine-masterfiles3[0-9]-* cfengine-masterfiles31[1-9]-*
.if !defined(MASTERDIR)
PKGNAMESUFFIX=	310
CONFLICTS+=	cfengine-masterfiles-3.*
.endif

RUN_DEPENDS=	cf-agent:sysutils/cfengine${PKGNAMESUFFIX}

FETCH_BEFORE_ARGS=	-o ${DISTDIR}/${DISTFILES}

CONFLICTS=	cfengine-masterfiles[6-9]*

MAKE_JOBS_UNSAFE=	yes
USES=		cpe gmake python:build shebangfix
HAS_CONFIGURE=	yes
EXAMPLESDIR=	${PREFIX}/share/examples/cfengine-masterfiles
CONFIGURE_ARGS=	--prefix=${EXAMPLESDIR}
SHEBANG_FILES=	modules/packages/yum \
		modules/packages/zypper
NO_ARCH=	yes

.include <bsd.port.mk>
