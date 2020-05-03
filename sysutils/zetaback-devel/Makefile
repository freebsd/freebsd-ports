# Created by: Cy Schubert <cy@FreeBSD.org>
# $FreeBSD$

PORTNAME=	zetaback
DISTVERSION=	${ZETABACK_COMMIT_DATE}
CATEGORIES=	sysutils
PKGNAMESUFFIX=	-devel
HASH=		78d1d082
ZETABACK_COMMIT_DATE=	2020.01.31

MAINTAINER=	cy@FreeBSD.org
COMMENT=	Zetaback ZFS backup and recovery management system

USE_GITHUB=	yes
GH_ACCOUNT=	omniti-labs
GH_TAGNAME=	${HASH}

CONFLICTS=	zetaback-1.*

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

OPTIONS_DEFINE=	LOCAL BETTER_COMPRESSION
LOCAL_DESC=	Avoid ssh for localhost backup
BETTER_COMPRESSION_DESC=	Allow different compressions for snapshots

LOCAL_EXTRA_PATCHES=	${PATCHDIR}/opt-localhost.in
BETTER_COMPRESSION_EXTRA_PATCHES=	${PATCHDIR}/opt-compression.in

USES=		autoreconf perl5
USE_PERL5=	run
GNU_CONFIGURE=	yes
NO_ARCH=	yes

.include <bsd.port.mk>
