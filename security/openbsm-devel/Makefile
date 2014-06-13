# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	openbsm
DISTVERSION=	1.2-alpha3
PORTREVISION=	3
CATEGORIES=	security
MASTER_SITES=	http://www.trustedbsd.org/downloads/ \
    		http://mirrors.rit.edu/zi/
PKGNAMESUFFIX=	-devel
EXTRACT_SUFX=	.tgz

MAINTAINER=	zi@FreeBSD.org
COMMENT=	Open Source Basic Security Module (BSM) Audit Implementation

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/LICENSE

CONFLICTS=	openbsm-1.[0-9]*

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

USE_RC_SUBR=	auditdistd
SUB_FILES=	pkg-message
PLIST_SUB=	USERS=${USERS} GROUPS=${GROUPS}

USERS=		auditdistd
GROUPS=		audit

VARAUDIT=	/var/audit

.include <bsd.port.pre.mk>

.if ${OSVERSION} <= 800000
IGNORE=		requires FreeBSD 8.x or above
.endif

.if ${OSVERSION} >= 1000000
IGNORE=		is not needed under FreeBSD 10.x or higher
.endif

post-install:
	@${MKDIR} -m 0770 ${STAGEDIR}${VARAUDIT}/dist
	@${MKDIR} -m 0700 ${STAGEDIR}${VARAUDIT}/remote

.include <bsd.port.post.mk>
