# New ports collection makefile for:   openradius
# Date created:        23 May 2003
# Whom:                Adam Jette <jettea46@yahoo.com>
#
# $FreeBSD$
#

PORTNAME=      openradius
PORTVERSION=   0.9.7
PORTREVISION=	1
CATEGORIES=    net
MASTER_SITES=  http://www.xs4all.nl/~evbergen/openradius/download/ \
	       http://www.mirrors.wiretapped.net/security/authentication/radius/openradius/

MAINTAINER=    jettea46@yahoo.com
COMMENT=       A RADIUS server with some actual documentation

CONFLICTS=	freeradius-0.* gnu-radius-1.* radiusd-cistron-1.*
CONFIGURE_ARGS=     --prefix={$PREFIX}

CC ?= gcc
CXX ?= g++
USE_GMAKE=     yes

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
