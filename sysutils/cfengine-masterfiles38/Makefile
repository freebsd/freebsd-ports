# Created by: cy@FreeBSD.org
# $FreeBSD$

PORTNAME=	cfengine-masterfiles
PORTVERSION=	3.8.2
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	https://cfengine-package-repos.s3.amazonaws.com/tarballs/

MAINTAINER=	cy@FreeBSD.org
#		gjb@FreeBSD.org is also committer for this port
#		skreuzer@FreeBSD.org is also committer for this port
COMMENT=	cfengine sample policies for installations and upgrades

LICENSE=	GPLv3

CPE_VENDOR=	gnu

CONFLICTS=	cfengine-masterfiles3[0-79]-* cfengine-masterfiles31[0-9]-*
.if !defined(MASTERDIR)
PKGNAMESUFFIX=	38
CONFLICTS+=	cfengine-masterfiles-3.*
.endif

RUN_DEPENDS=	cf-agent:sysutils/cfengine${PKGNAMESUFFIX}

FETCH_BEFORE_ARGS=	-o ${DISTDIR}/${DISTFILES}

CONFLICTS=	cfengine-masterfiles[1679]*

MAKE_JOBS_UNSAFE=	yes
USES=		cpe python:build shebangfix
HAS_CONFIGURE=	yes
EXAMPLESDIR=	${PREFIX}/share/examples/cfengine-masterfiles
CONFIGURE_ARGS=	--prefix=${EXAMPLESDIR}
SHEBANG_FILES=	modules/packages/apt_get \
		modules/packages/yum

.include <bsd.port.mk>
