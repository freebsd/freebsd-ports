# New ports collection makefile for:	bgrab
# Date created:		20 March 2000
# Whom:			Kelly Yancey <kbyanc@posi.net>
#
# $FreeBSD$
#

PORTNAME=	bgrab
PORTVERSION=	1.3.6
CATEGORIES=	news
MASTER_SITES=	http://bgrab.ifip.net/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Binary Grabber - downloads binaries from newsgroups

RUN_DEPENDS=	mmencode:${PORTSDIR}/converters/mmencode

EXTRACT_AFTER_ARGS=	| ${TAR} -zxf -

USE_BZIP2=	yes
MAKEFILE=	${FILESDIR}/Makefile.dist
MAKE_ENV=	INSTALL_PROGRAM="${INSTALL_PROGRAM}"
PLIST_FILES=	bin/bgrab

.include <bsd.port.mk>
