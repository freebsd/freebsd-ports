# ex:ts=8
# Ports collection makefile for:	mmail
# Date created:			18 September 2002
# Whom:				Frederic Cambus
#
# $FreeBSD$
#

PORTNAME=	mmail
PORTVERSION=	0.45
PORTREVISION=	1
CATEGORIES=	news
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	multimail \
			system/bbs/mail

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Offline BBS mail packet reader supporting QWK/OMEN/SOUP/OPX/BLUEWAVE

RUN_DEPENDS=	zip:${PORTSDIR}/archivers/zip \
		unzip:${PORTSDIR}/archivers/unzip

USE_GMAKE=	yes
MAKE_ARGS=	OPTS=""

MAN1=		mmail.1
PLIST_FILES=	bin/mmail

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mm ${PREFIX}/bin/mmail
	${INSTALL_MAN} ${WRKSRC}/mm.1 ${MANPREFIX}/man/man1/mmail.1

.include <bsd.port.mk>
