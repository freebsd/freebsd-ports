# ex:ts=8
# Ports collection makefile for:	libtre
# Date created:			Oct 14, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libtre
PORTVERSION=	0.3.2
CATEGORIES=	textproc
MASTER_SITES=	http://kouli.iki.fi/~vlaurika/libtre/

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	A lightweight fully POSIX compliant regexp matching library

USE_BZIP2=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500028
IGNORE=		"need wchar support"
.endif

.include <bsd.port.post.mk>
