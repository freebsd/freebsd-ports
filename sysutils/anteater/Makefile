# ex:ts=8
# New ports collection makefile for:	anteater
# Date created:			Aug 13, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	anteater
PORTVERSION=	0.4
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.profzone.ch/drzoom/anteater/

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	A MTA log analyzer

GNU_CONFIGURE=	yes

.include <bsd.port.pre.mk>

# You will still get configure errors on -STABLE
#  if you set CXX to a GCC3 incarnation!
.if ${OSVERSION} < 500035
CONFIGURE_ARGS=	--enable-strstream
.endif

.include <bsd.port.post.mk>
