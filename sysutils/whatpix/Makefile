# New ports collection makefile for:   mtf
# Date created:        02 June 2002
# Whom:                Philippe Casidy <pcasidy@casidy.com>
#
# $FreeBSD$
#

PORTNAME=	whatpix
PORTVERSION=	1.2
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://whatpix.sourceforge.net/download/

MAINTAINER=	pcasidy@casidy.com
COMMENT=	Perl console application which finds, moves, or deletes duplicate files

RUN_DEPENDS=	p5-Digest-SHA1>=0:${PORTSDIR}/security/p5-Digest-SHA1

NO_BUILD=	yes
PLIST_FILES=	bin/whatpix
USE_PERL5_RUN=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/whatpix ${PREFIX}/bin

.include <bsd.port.mk>
