# Ports collection makefile for:  pear-HTTP_Session
# Date created:			  13 December 2003
# Whom:				  Alex Miller (<asm@asm.kiev.ua>)
#
# $FreeBSD$
#

PORTNAME=	HTTP_Session
PORTVERSION=	0.4
CATEGORIES=	www devel pear

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PEAR Object-oriented interface to the session_* family functions

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear-PEAR
RUN_DEPENDS=	${BUILD_DEPENDS}

FILES=		Session.php Session/Container.php Session/Container/DB.php
EXAMPLES=	HTTP_Session_Example.php sessiondata.sql
_EXAMPLESDIR=	docs

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"
.include <bsd.port.post.mk>
