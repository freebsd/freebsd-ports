# ex:ts=8
# New ports collection makefile for:	ipcalc
# Date created:			May 21, 2001
# Whom:				ijliao
#
# $FreeBSD$

PORTNAME=	ipcalc
PORTVERSION=	0.35
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://jodies.de/
DISTNAME=	ipcalc.pl
EXTRACT_SUFX=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	petef@FreeBSD.org
COMMENT=	IP Calculator

PLIST_FILES=	bin/ipcalc
NO_BUILD=	yes
USE_PERL5=	yes

do-install:
	${INSTALL_SCRIPT} ${DISTDIR}/${DISTFILES} ${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
