# New ports collection makefile for:	wmnd
# Date created:				29 October 2001
# Whom:					Paolo Pisati <flag@gufi.org>
#
# $FreeBSD$
#

PORTNAME=	wmnd
PORTVERSION=	0.4.16
CATEGORIES=	net
MASTER_SITES=	http://www.thregr.org/~wavexx/software/wmnd/releases/
MASTER_SITE_SUBDIR=	distfiles

MAINTAINER=	garga@FreeBSD.org
COMMENT=	Improved network monitoring dock app (with tons of features)

LICENSE=	GPLv2

OPTIONS_DEFINE=	EXAMPLES
OPTIONS_DEFAULT=EXAMPLES

USE_XORG=	ice sm x11 xext xpm
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes
CONFIGURE_ARGS=	--disable-dummy-driver

MAN1=		wmnd.1
PORTEXAMPLES=	wmndrc
PLIST_FILES=	bin/wmnd

.include <bsd.port.pre.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/wmnd ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/wmnd.1 ${MANPREFIX}/man/man1
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/wmndrc ${EXAMPLESDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
