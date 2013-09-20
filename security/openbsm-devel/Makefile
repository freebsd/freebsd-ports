# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	openbsm
DISTVERSION=	1.2-alpha3
PORTREVISION=	1
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
MAN1=		auditreduce.1 praudit.1
MAN2=		audit.2	auditctl.2 auditon.2 getaudit.2	getauid.2 setaudit.2 \
		setauid.2
MAN3=		au_class.3 au_control.3	au_domain.3 au_errno.3 au_event.3 \
		au_fcntl_cmd.3 au_free_token.3 au_io.3 au_mask.3 au_open.3 \
		au_socket_type.3 au_token.3 au_user.3 libauditd.3 libbsm.3
MAN5=		audit.log.5 auditdistd.conf.5 audit_class.5 audit_control.5 \
		audit_event.5 audit_user.5 audit_warn.5
MAN8=		auditfilterd.8 audit.8 auditd.8 auditdistd.8

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${OSVERSION} <= 800000
IGNORE=		requires FreeBSD 8.x or above
.endif

.if ${OSVERSION} >= 1000000
IGNORE=		is not needed under FreeBSD 10.x or higher
.endif

post-install:
	@${MKDIR} -m 0770 ${VARAUDIT}/dist
	@${MKDIR} -m 0700 ${VARAUDIT}/remote
	@${CHOWN} ${USERS}:${GROUPS} ${VARAUDIT}/dist
	@${CHOWN} ${USERS}:wheel ${VARAUDIT}/remote
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
