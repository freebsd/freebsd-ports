# New ports collection makefile for:	openbsm
# Date created:				Jun 13 2006
# Whom:					Florent Thoumie <flz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	openbsm
DISTVERSION=	1.1-p1
CATEGORIES=	security
MASTER_SITES=	http://www.trustedbsd.org/downloads/
DISTFILES=	openbsm-${DISTVERSION}.tgz

MAINTAINER=	flz@FreeBSD.org
COMMENT=	Open Source Basic Security Module (BSM) Audit Implementation
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

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
		au_domain.3		\
		au_errno.3		\
		au_event.3		\
		au_fcntl_cmd.3		\
		au_free_token.3		\
		au_io.3			\
		au_mask.3		\
		au_open.3		\
		au_socket_type.3	\
		au_token.3		\
		au_user.3		\
		libauditd.3		\
		libbsm.3
MAN5=		audit.log.5		\
		audit_class.5		\
		audit_control.5		\
		audit_event.5		\
		audit_user.5		\
		audit_warn.5
MAN8=		auditfilterd.8		\
		audit.8			\
		auditd.8

.include <bsd.port.mk>
