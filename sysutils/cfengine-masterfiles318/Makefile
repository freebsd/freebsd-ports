PORTNAME=	cfengine-masterfiles
PORTVERSION=	3.18.2
CATEGORIES=	sysutils
MASTER_SITES=	https://cfengine-package-repos.s3.amazonaws.com/tarballs/

MAINTAINER=	cy@FreeBSD.org
COMMENT=	cfengine sample policies for installations and upgrades

DEPRECATED=		Expire one year after cfengine-masterfiles 3.19.0 released
EXPIRATION_DATE=	2023-07-02

LICENSE=	GPLv3

CPE_VENDOR=	gnu
CPE_PRODUCT=	cfengine

CONFLICTS=	cfengine-masterfiles3[0-9] cfengine-masterfiles31[0-79]
.if !defined(MASTERDIR)
PKGNAMESUFFIX=	318
CONFLICTS+=	cfengine-masterfiles-3.*
.endif

RUN_DEPENDS=	cf-agent:sysutils/cfengine${PKGNAMESUFFIX}

FETCH_BEFORE_ARGS=	-o ${DISTDIR}/${DISTFILES}

MAKE_JOBS_UNSAFE=	yes
USES=		cpe gmake python:build
HAS_CONFIGURE=	yes
EXAMPLESDIR=	${PREFIX}/share/examples/cfengine-masterfiles
CONFIGURE_ARGS=	--prefix=${EXAMPLESDIR}

.include <bsd.port.mk>
