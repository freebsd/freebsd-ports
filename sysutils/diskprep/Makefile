# Ports collection makefile for:	diskprep
# Date created:				Friday, May 7, 2004
# Whom:					Brooks Davis <brooks@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	diskprep
PORTVERSION=	1.0.1
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://people.freebsd.org/~brooks/diskprep/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	brooks

MAINTAINER=	brooks@FreeBSD.org
COMMENT=	A program to prepare disks for use based on a config file

DEPRECATED=	Believed to have no users
EXPIRATION_DATE=	2012-09-01

USE_BZIP2=	yes
USE_PERL5_RUN=	yes
MAKE_ENV+=	EXAMPLESDIR=${EXAMPLESDIR}

USE_RC_SUBR=	${PORTNAME}

MAN8=		diskprep.8
MANCOMPRESSED=	yes

.include <bsd.port.mk>
