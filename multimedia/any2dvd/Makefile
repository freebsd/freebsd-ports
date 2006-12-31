#
# Ports collection makefile for:        any2dvd
# Date created:                         28 December 2006
# GRRR.  Why is this breach of grammar necessary?
# Whom:                                 Greg Lehey <grog@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	any2dvd
PORTVERSION=	0.32
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	any2dvd

MAINTAINER=	grog@FreeBSD.org
COMMENT=	A script to ease the pain of burning multimedia DVDs
# IGNORE=		More problems than you can shake a stick at.  Shall we delete it?

RUN_DEPENDS=	transcode:${PORTSDIR}/multimedia/transcode	\
		seq2:${PORTSDIR}/misc/seq2			\
		soundstretch:${PORTSDIR}/audio/soundtouch	\
		ecasound:${PORTSDIR}/audio/ecasound
LIB_DEPENDS+=	Magick.10:${PORTSDIR}/graphics/ImageMagick

MAN1=	any2vob.1 any2dvd.1

PLIST_FILES=	bin/any2dvd		\
		bin/any2vob

NO_BUILD=	yes

USE_BZIP2=	yes
USE_GHOSTSCRIPT_RUN=	yes

do-install:
# scripts
	@${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${WRKSRC}/any2vob ${PREFIX}/bin
# Man pages!  What luxury!
	${INSTALL_MAN} ${WRKSRC}/any2dvd.1  ${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/any2vob.1  ${MANPREFIX}/man/man1

post-install:
	@${CAT} ${PKGMESSAGE}

all:

.include <bsd.port.mk>
