# New ports collection makefile for:	libpri
# Date created:				25 Oct 2004
# Whom:					Alexander Timoshenko <gonzo@univ.kiev.ua>
#
# $FreeBSD$
#

PORTNAME=	libpri
PORTVERSION=	1.0.2
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.asterisk.org/pub/libpri/ \
		ftp://ftp.asterisk.org/pub/libpri/old/

MAINTAINER=	gonzo@univ.kiev.ua
COMMENT=	A C implementation of the Primary Rate ISDN specification

USE_GMAKE=	yes
INSTALLS_SHLIB= yes

.include <bsd.port.pre.mk>

.if ${ARCH} == "alpha"
BROKEN=		"Does not compile on alpha"
.endif

post-patch:
	@${FIND} ${WRKSRC} -name \*.orig -or -name \*.bak -delete

.include <bsd.port.post.mk>
