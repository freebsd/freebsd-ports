# Created by: Slaven Rezic <slaven@rezic.de>
# $FreeBSD$

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
		cabextract:${PORTSDIR}/archivers/cabextract \
		cdrecord:${PORTSDIR}/sysutils/cdrtools
.endif

USES=		perl5

NO_BUILD=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--default --prefix=${PREFIX}

PLIST_FILES=	bin/lesspipe.sh bin/code2color man/man1/lesspipe.1.gz

SUB_FILES=	pkg-message

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/code2color  ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/lesspipe.sh ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN}    ${WRKSRC}/lesspipe.1  ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
