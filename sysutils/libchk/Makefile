# New ports collection makefile for:	libchk
# Date created:		2 September 2002
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	libchk
PORTVERSION=	1.6
CATEGORIES=	sysutils
MASTER_SITES=	http://www.iDaemons.org/distfiles/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	knu

MAINTAINER=	knu@FreeBSD.org

USE_BZIP2=	yes
USE_RUBY=	yes

MAKE_ARGS=	PREFIX="${PREFIX}"

MAN1=		libchk.1
MANCOMPRESSED=	maybe

.include <bsd.port.pre.mk>

.if ${RUBY_VER} < 1.7
RUN_DEPENDS+=	${RUBY_SITELIBDIR}/optparse.rb:${PORTSDIR}/lang/ruby16-shim-ruby18
.endif

.include <bsd.port.post.mk>
