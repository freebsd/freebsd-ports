# New ports collection makefile for:	django-devel
# Date created:				Jul 04 2006
# Whom:					Florent Thoumie <flz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	django-devel
PORTVERSION=	${SNAPSHOT}
PORTREVISION=	0
MASTER_SITES=	${MASTER_SITE_LOCAL:S/$/:freebsd/g}
MASTER_SITE_SUBDIR=	flz/django/:freebsd
DISTFILES=	Django-${PORTVERSION}.tar.gz:freebsd
SNAPSHOT=	20060704
DJANGOVER=	0.95

MAINTAINER=	flz@FreeBSD.org
COMMENT=	High-level Python Web framework

CONFLICTS=	py2[0-9]-django-[0-9]*

MASTERDIR=	${.CURDIR}/../py-django
MD5_FILE=	${.CURDIR}/distinfo
PLIST=		${.CURDIR}/pkg-plist

.include "${MASTERDIR}/Makefile"
