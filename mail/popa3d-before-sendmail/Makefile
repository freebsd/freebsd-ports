# New ports collection makefile for:	popa3d-before-sendmail
# Date created:		13.Jan 2003
# Whom:			dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

CATEGORIES=	mail

MAINTAINER=	dinoex@FreeBSD.org

SMTP_AFTER_POP3=	yes
MASTERDIR?=	${.CURDIR}/../popa3d

.if exists(${.CURDIR}/Makefile.local)
.include "${.CURDIR}/Makefile.local"
.endif

.include "${MASTERDIR}/Makefile"
