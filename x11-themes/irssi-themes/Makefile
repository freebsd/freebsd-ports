# New ports collection makefile for:	irssi-themes
# Date created:				17 Sep 2006
# Whom:					Emanuel Haupt <ehaupt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	irssi-themes
PORTVERSION=	20071213
PORTREVISION=	1
CATEGORIES=	x11-themes irc
MASTER_SITES=	http://www.irssi.org/themefiles/ \
		CRITICAL
MASTER_SITE_SUBDIR=	${PORTNAME}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	A collection of additional irssi themes

RUN_DEPENDS=	irssi:${PORTSDIR}/irc/irssi

NO_BUILD=	yes

PLIST=		${WRKDIR}/pkg-plist

THEMESDIR_REL=	share/irssi/themes

.include <bsd.port.pre.mk>
.include "${MASTERDIR}/Makefile.inc"

pre-install:
.for f in ${DISTFILES}
	@${ECHO_CMD} "${THEMESDIR_REL}/${f}" >> ${PLIST}
.endfor

do-extract:
	@${MKDIR} ${WRKSRC}
.for f in ${DISTFILES}
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/${f} ${WRKSRC}
.endfor

do-install:
.for f in ${DISTFILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/${THEMESDIR_REL}/
.endfor

.include <bsd.port.post.mk>
