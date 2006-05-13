# ex:ts=8	-*-mode: makefile-*-
#
# New ports collection makefile for:	netrik
# Date created:		2002-12-23
# Whom:			Alan Eldridge <alane@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	netrik
PORTVERSION=	1.15.3
PORTREVISION=	0
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ale@FreeBSD.org
COMMENT=	A text web browser, very ambitious, in active development

RUN_DEPENDS=	wget:${PORTSDIR}/ftp/wget

USE_GMAKE=	yes
USE_GETOPT_LONG=yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

MAN1=		netrik.1
MAN5=		netrikrc.5

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 400000
LIB_DEPENDS+=	ncurses.5:${PORTSDIR}/devel/ncurses
.endif

.if defined(NOPORTDOCS)
post-patch:
	@${REINPLACE_CMD} "s/install-data-am: install-docDATA/install-data-am:/" \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} "s/install-docDATA install-man/install-man/" \
		${WRKSRC}/doc/Makefile.in
.endif

.include <bsd.port.post.mk>
