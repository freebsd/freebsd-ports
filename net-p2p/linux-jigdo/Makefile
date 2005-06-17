# ex:ts=8
# Ports collection makefile for:  linux-jigdo
# Date created:			  21 July 2002
# Whom:				  Udo Schweigert
#
# $FreeBSD$
#

PORTNAME=	jigdo
PORTVERSION=	0.7.1
#PORTREVISION?=	0
CATEGORIES=	net
MASTER_SITES=	http://atterer.net/jigdo/
PKGNAMEPREFIX=	linux-
DISTNAME=	jigdo-bin-${PORTVERSION}

MAINTAINER=	udo.schweigert@siemens.com
COMMENT=	A tool designed to ease the distribution of very large files

RUN_DEPENDS=	wget:${PORTSDIR}/ftp/wget

ONLY_FOR_ARCHS=	i386
USE_BZIP2=	YES
USE_LINUX=	yes
NO_BUILD=	yes

PROGRAMS=	jigdo-file
SCRIPTS=	jigdo-lite jigdo-mirror

MAN1=		jigdo-file.1 jigdo-lite.1 jigdo-mirror.1

pre-install:
	@${BRANDELF} -t Linux ${WRKSRC}/jigdo-file

do-install:
.for i in ${PROGRAMS}
	@${INSTALL_PROGRAM} ${WRKSRC}/$i ${PREFIX}/bin
.endfor
.for i in ${SCRIPTS}
	@${INSTALL_SCRIPT} ${WRKSRC}/$i ${PREFIX}/bin
.endfor
.for i in ${PROGRAMS} ${SCRIPTS}
	@${INSTALL_MAN} ${WRKSRC}/$i.1 ${PREFIX}/man/man1
.endfor

.include <bsd.port.mk>
