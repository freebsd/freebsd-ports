# New ports collection makefile for:	bittorrent
# Date created:				12 April 2003
# Whom:					mdodd@freebsd.org
#
# $FreeBSD$
#

PORTNAME=	BitTorrent
PORTVERSION=	3.2.1b
CATEGORIES=	net python
MASTER_SITES=	http://bitconjurer.org/BitTorrent/

MAINTAINER=	mdodd@freebsd.org
COMMENT=	"Peer to Peer file sharing/mirroring."

RUN_DEPENDS=    ${PYTHON_SITELIBDIR}/wxPython/wxc.so:${PORTSDIR}/x11-toolkits/py-wxPython

USE_PYTHON=	yes

MAN1=		BitTorrent.1
MLINKS=		BitTorrent.1 bittorrent.1

do-build:
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}

do-install:
	@${MKDIR} ${PREFIX}/share/BitTorrent
	@(cd ${WRKSRC} && ${TAR} --exclude .cvsignore \
		--exclude "*.orig" --exclude osx -c -f - .) \
		| (cd ${PREFIX}/share/BitTorrent && ${TAR} --unlink -x -f -)
	@printf "#!/bin/sh\n${PYTHON_CMD} \
		${PREFIX}/share/BitTorrent/btdownloadgui.py \044*\n" \
		> ${WRKDIR}/BitTorrent.sh
	@${INSTALL_SCRIPT} ${WRKDIR}/BitTorrent.sh ${PREFIX}/bin/BitTorrent
	@${INSTALL_MAN} ${FILESDIR}/BitTorrent.1 ${PREFIX}/man/man1/BitTorrent.1
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
