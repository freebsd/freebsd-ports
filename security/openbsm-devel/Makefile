# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	openbsm
DISTVERSION=	1.2-alpha4
CATEGORIES=	security
MASTER_SITES=	http://www.trustedbsd.org/downloads/ \
		http://mirrors.rit.edu/zi/
PKGNAMESUFFIX=	-devel

MAINTAINER=	zi@FreeBSD.org
COMMENT=	Open Source Basic Security Module (BSM) Audit Implementation

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

IGNORE=		is not needed under FreeBSD 10.x or higher
DEPRECATED=	${IGNORE}
EXPIRATION_DATE=	2017-01-15

CONFLICTS=	openbsm-1.[0-9]*

GNU_CONFIGURE=	yes
USES=		libtool tar:tgz
USE_LDCONFIG=	yes

USE_RC_SUBR=	auditdistd
SUB_FILES=	pkg-message
PLIST_SUB=	USERS=${USERS} GROUPS=${GROUPS} NEEDVARDIRS=${NEEDVARDIRS}

USERS=		auditdistd
GROUPS=		audit

VARAUDIT=	/var/audit

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 902000
NEEDVARDIRS=	""
.else
NEEDVARDIRS=	"@comment "
.endif

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libauditd.so.0.0.0
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libbsm.so.0.0.0
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/auditfilter_noop.so.0.0.0
.if ${OSVERSION} < 902000
	@${MKDIR} -m 0770 \
		${STAGEDIR}${VARAUDIT}/dist ${STAGEDIR}${VARAUDIT}/remote
.endif

.include <bsd.port.post.mk>
