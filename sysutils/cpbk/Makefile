# New ports collection makefile for: cpbk
# Date created:		12 April 1999
# Whom:			Sergey Osokin aka oZZ <ozz@FreeBSD.org.ru>
#
# $FreeBSD$
#

PORTNAME=	cpbk
PORTVERSION=	2.0
CATEGORIES=	sysutils
MASTER_SITES=	http://www.netsw.org/system/tools/fileutils/install/cpbk/ \
		http://pep.netnation.com/cpbk/ \
		ftp://mocha.mkintraweb.com/pub/linux/cpbk/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Backup Copy programm

MAN1=		cpbk.1
MANCOMPRESSED=	yes
PLIST_FILES=	bin/cpbk

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/cpbk ${PREFIX}/bin

post-install:
	@${INSTALL_MAN} $(WRKSRC)/cpbk.1.gz $(PREFIX)/man/man1

.include <bsd.port.mk>
