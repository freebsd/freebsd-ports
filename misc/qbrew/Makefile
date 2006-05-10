# New ports collection makefile for:	qbrew
# Date created:				22 September 2000
# Whom:					David Johnson <david@usermode.org>
#
# $FreeBSD$
#

PORTNAME=	qbrew
PORTVERSION=	0.3.5
CATEGORIES=	misc
MASTER_SITES=	http://www.usermode.org/code/

MAINTAINER=	david@usermode.org
COMMENT=	A homebrewer's recipe calculator

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_QT_VER=	3
PORTDOCS=	*
QT_NONSTANDARD=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=		--x-includes=${X11BASE}/include	\
			--x-libraries=${X11BASE}/lib

.include <bsd.port.pre.mk>

post-patch:
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -E 's,^(SUBDIRS = .*) docs,\1,' \
		${WRKSRC}/Makefile.in
.endif

post-install:
	${STRIP_CMD} ${PREFIX}/bin/qbrew

.include <bsd.port.post.mk>
