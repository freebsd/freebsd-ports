# New ports collection makefile for:   lesspipe
# Date created:        11 December 2004
# Whom:                Slaven Rezic <slaven@rezic.de>
#
# $FreeBSD$
#

PORTNAME=	lesspipe
PORTVERSION=	1.43
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	lesspipe

MAINTAINER=	slaven@rezic.de
COMMENT=	A preprocessor for less

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash

.if defined(WITH_FANCY)
BUILD_DEPENDS+=	zip:${PORTSDIR}/archivers/zip \
		rpm:${PORTSDIR}/archivers/rpm \
		dpkg:${PORTSDIR}/archivers/dpkg \
		antiword:${PORTSDIR}/textproc/antiword \
		lynx:${PORTSDIR}/www/lynx \
		pdftotext:${PORTSDIR}/graphics/xpdf \
		unrtf:${PORTSDIR}/textproc/unrtf \
		dvi2tty:${PORTSDIR}/print/dvi2tty \
		pstotext:${PORTSDIR}/print/pstotext \
		mp3info:${PORTSDIR}/audio/mp3info \
		isoinfo:${PORTSDIR}/sysutils/cdrtools \
		cabextract:${PORTSDIR}/archivers/cabextract
.endif

USE_PERL5=	yes

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--default --prefix=${PREFIX}

PLIST_FILES=	bin/lesspipe.sh \
		bin/code2color

PKGMESSAGE=	${WRKDIR}/pkg-message
SUB_FILES=	pkg-message

do-build:

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
