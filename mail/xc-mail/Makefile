# New ports collection makefile for:	xc-mail
# Date created:		2000-10-01
# Whom:			trevor
#
# $FreeBSD$
#

PORTNAME=	xc-mail
PORTVERSION=	2.2
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	xcmail

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Mail client for X which supports POP and PGP

LIB_DEPENDS=	Xclasses.1:${PORTSDIR}/x11-toolkits/xclasses

GNU_CONFIGURE=	yes
ONLY_FOR_ARCHS=	arm i386
USE_GMAKE=	yes
USE_X_PREFIX=	yes

CONFIGURE_ARGS=	--includedir=${X11BASE}/include/ \
		--libdir=${X11BASE}/lib/ \
		--x-includes=${X11BASE}/include/ \
		--x-libraries=${X11BASE}/lib/

CONFIGURE_ENV=	CPPFLAGS="-I${X11BASE}/include" \
		LDFLAGS="-L${X11BASE}/lib" \
		LIBS="-L${X11BASE}/lib"

.include <bsd.port.pre.mk>

post-patch:
.if ${OSVERSION} > 502014
	@${REINPLACE_CMD} -e "s|expr $1|expr -- $1|g" ${WRKSRC}/plugins/linkshared.in
	@${REINPLACE_CMD} -e "s|expr $1|expr -- $1|g" ${WRKSRC}/src/linktool
.endif

post-install:
		chown ${BINOWN}:mail ${PREFIX}/bin/xc-mail
		chmod g+s ${PREFIX}/bin/xc-mail

.include <bsd.port.post.mk>
