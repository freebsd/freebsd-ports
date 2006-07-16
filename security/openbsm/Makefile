# New ports collection makefile for:	openbsm
# Date created:				Jun 13 2006
# Whom:					Florent Thoumie <flz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	openbsm
DISTVERSION=	1.0-alpha7
CATEGORIES=	security
MASTER_SITES=	http://www.trustedbsd.org/downloads/
DISTFILES=	openbsm-${DISTVERSION}.tgz

MAINTAINER=	flz@FreeBSD.org
COMMENT=	Open Source Basic Security Module (BSM) Audit Implementation
WRKSRC=		${WRKDIR}/${PORTNAME}
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes

MAN1=		auditreduce.1		\
		praudit.1
MAN2=		audit.2			\
		auditctl.2		\
		auditon.2		\
		getaudit.2		\
		getauid.2		\
		setaudit.2		\
		setauid.2
MAN3=		au_class.3		\
		au_control.3		\
		au_event.3		\
		au_free_token.3		\
		au_io.3			\
		au_mask.3		\
		au_open.3		\
		au_token.3		\
		au_user.3		\
		libbsm.3
MAN5=		audit.log.5		\
		audit_class.5		\
		audit_control.5		\
		audit_event.5		\
		audit_user.5		\
		audit_warn.5
MAN8=		auditfilterd.8

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		does not compile on 4.X
.else
.if ${OSVERSION} < 600000
BROKEN=		does not package on 5.X
.endif
.endif

.if ( ( ${OSVERSION} < 500000 && ${OSVERSION} > 491101 ) || \
	( ${OSVERSION} < 600000 && ${OSVERSION} > 503100 ) || \
	${OSVERSION} >= 600000 )
MAN8+=		audit.8			\
		auditd.8

PLIST_FILES+=	sbin/audit		\
		sbin/auditd
.endif

.include <bsd.port.post.mk>
