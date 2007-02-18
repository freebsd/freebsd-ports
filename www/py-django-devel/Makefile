# New ports collection makefile for:	django-devel
# Date created:				Jul 04 2006
# Whom:					Florent Thoumie <flz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	django-devel
PORTVERSION=	${SNAPSHOT}
PORTREVISION=	0
MASTER_SITES=	http://www.cs.nctu.edu.tw/~lwhsu/ports/distfiles/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	clsung/django
DISTFILES=	Django-${PORTVERSION}.tar.gz
SNAPSHOT=	20070214
DJANGOVER=	0.95

MAINTAINER=	python@FreeBSD.org
COMMENT=	High-level Python Web framework

CONFLICTS=	py2[0-9]-django-[0-9]*

MASTERDIR=	${.CURDIR}/../py-django
MD5_FILE=	${.CURDIR}/distinfo
PLIST=		${.CURDIR}/pkg-plist

.include "${MASTERDIR}/Makefile"
