# New ports collection makefile for:	sigit
# Date created:				18 August 2001
# Whom:					petef
#
# $FreeBSD$
#

PORTNAME=	sigit
PORTVERSION=	0.3.0
CATEGORIES=	mail
MASTER_SITES=	http://www.redhead.dk/download/stable/
DISTNAME=	Sigit-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A tool to create random signatures

BUILD_DEPENDS=	${LOCALBASE}/bin/boxes:${PORTSDIR}/misc/boxes

LICENSE=	GPLv2

USE_PERL5_BUILD=	yes
USE_GMAKE=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${DATADIR} \
		--bin-dir=${PREFIX}/bin \
		--man-dir=${PREFIX}/man \
		--etc-dir=${PREFIX}/etc

MAN1=	sigit.1 sigitdb.1
MAN5=	sigit.rc.5

post-patch:
	@${MV} ${WRKSRC}/data/sigit.rc ${WRKSRC}/data/sigit.rc.dist

post-install:
	@(if [ ! -f ${PREFIX}/etc/sigit.rc ]; then \
		${CP} ${PREFIX}/etc/sigit.rc.dist ${PREFIX}/etc/sigit.rc; fi)

.include <bsd.port.mk>
