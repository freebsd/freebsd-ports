# ex:ts=8
# Ports collection makefile for:  tea-total
# Date created:			  Tue Dec 19, 2000
# Whom:				  David O'Brien (obrien@NUXI.com)
#
# $FreeBSD$
#

PORTNAME=	tea-total
PORTVERSION=	0.1
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.linuxhacker.org/pub/tea-total/  \
		http://www.linuxhacker.org/tea-total/

MAINTAINER=     obrien@FreeBSD.org

#	code is not 64-bit clean...
ONLY_FOR_ARCHS=	i386

post-install:
	cd ${WRKSRC} ; ${INSTALL_PROGRAM} tea tea-keygen untea ${PREFIX}/bin

.include <bsd.port.mk>
