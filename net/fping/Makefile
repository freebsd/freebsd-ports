# ex:ts=8
# Ports collection makefile for:  fping
# Date created:			  Tue Mar 25, 1997
# Whom:				  David O'Brien (obrien@NUXI.com)
#
# $FreeBSD$
#

PORTNAME=	fping
PORTVERSION=	1.20
DISTNAME=	part01
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.uu.net/usenet/comp.sources.unix/volume26/fping/ \
		ftp://ftp.digital.com/pub/usenet/comp.sources.unix/volume26/fping/ \
		ftp://ftp.wustl.edu/usenet/comp.sources.unix/volume26/fping/ \
		ftp://ftp.isnet.is/pub/Usenet/Usenet.src/comp.sources.unix/v26/fping/
DISTNAME=	part01
EXTRACT_SUFX=	.Z

MAINTAINER=	obrien@FreeBSD.org

DIST_SUBDIR=	fping
EXTRACT_CMD=	zcat
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	| ${SED} -e '1,/Archive-Name/d' | ${SH}
NO_WRKSUBDIR=	yes
MAN8=		fping.8


post-install:
	@strip ${PREFIX}/sbin/fping

.include <bsd.port.mk>
