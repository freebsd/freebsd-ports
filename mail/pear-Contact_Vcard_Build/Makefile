# Ports collection makefile for:  pear-Contact_Vcard_Build
# Date created:			  30 May 2005
# Whom:				  Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
#
# $FreeBSD$
#

PORTNAME=	Contact_Vcard_Build
PORTVERSION=	1.1.2
CATEGORIES=	mail www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PEAR class to build (create) and fetch vCard 2.1 and 3.0 text blocks

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${BUILD_DEPENDS}

FILES=		Contact_Vcard_Build.php\
		Contact/Vcard/Build.php
TESTS=		AllTests.php \
		bug-15348.phpt \
		build-email.phpt \
		build-foobar.phpt \
		build-johndoe.phpt

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
