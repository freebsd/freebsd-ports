# New ports collection makefile for:   lesspipe
# Date created:        11 December 2004
# Whom:                Slaven Rezic <slaven@rezic.de>
#
# $FreeBSD$
#

PORTNAME=	lesspipe
PORTVERSION=	1.55
CATEGORIES=	misc
MASTER_SITES=	SF

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
		cabextract:${PORTSDIR}/archivers/cabextract
USE_CDRTOOLS=	yes
.endif

USE_PERL5=	yes

NO_BUILD=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--default --prefix=${PREFIX}

PLIST_FILES=	bin/lesspipe.sh \
		bin/code2color

SUB_FILES=	pkg-message

MAN1=		lesspipe.1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/code2color  ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/lesspipe.sh ${PREFIX}/bin
	${INSTALL_MAN}    ${WRKSRC}/lesspipe.1  ${PREFIX}/man/man1

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
