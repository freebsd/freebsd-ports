# Ports collection makefile for:	diskprep
# Date created:				Friday, May 7, 2004
# Whom:					Brooks Davis <brooks@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	diskprep
PORTVERSION=	1.0.0
CATEGORIES=	sysutils
MASTER_SITES=	http://people.freebsd.org/~brooks/diskprep/

MAINTAINER=	brooks@FreeBSD.org
COMMENT=	A program to prepare disks for use based on a config file

USE_BZIP2=	yes
USE_PERL5_RUN=	yes
MAKE_ENV+=	EXAMPLESDIR=${EXAMPLESDIR}

USE_RCORDER=	${NAME}

MAN8=		diskprep.8
MANCOMPRESSED=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 503000
IGNORE=		Requires glabel(8) and thus >= FreeBSD-5.3
.endif

.include <bsd.port.post.mk>
