# Ports collection makefile for:	diskprep
# Date created:				Friday, May 7, 2004
# Whom:					Brooks Davis <brooks@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	diskprep
PORTVERSION=	0.9.2
CATEGORIES=	sysutils
MASTER_SITES=	http://people.freebsd.org/~brooks/diskprep/

MAINTAINER=	brooks@FreeBSD.org
COMMENT=	A program to prepare disks for use based on a config file

USE_BZIP2=	yes
USE_PERL5_RUN=	yes
MAKE_ENV+=	EXAMPLESDIR=${EXAMPLESDIR}

MAN8=		diskprep.8
MANCOMPRESSED=	yes

.include <bsd.port.mk>
