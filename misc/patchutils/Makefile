# ex:ts=8
# New ports collection makefile for:	patchutils
# Date created:			Jul 23, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	patchutils
PORTVERSION=	0.2.19
PORTREVISION=	0
CATEGORIES=	misc
MASTER_SITES=	http://cyberelk.net/tim/data/patchutils/stable/

MAINTAINER=	ports@FreeBSD.org

RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash2

USE_BZIP2=	yes
USE_PERL5=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

MAN1=	combinediff.1 dehtmldiff.1 editdiff.1 filterdiff.1 fixcvsdiff.1 \
	grepdiff.1 interdiff.1 lsdiff.1 recountdiff.1 rediff.1 splitdiff.1 \
	unwrapdiff.1

post-patch:
	@${PERL} -pi -e "s,/bin/bash,${LOCALBASE}/bin/bash," ${WRKSRC}/editdiff.in

.include <bsd.port.mk>
