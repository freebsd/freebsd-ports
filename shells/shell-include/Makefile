# New ports collection makefile for: qar-bufo
# Date created:        18 April 2007
# Whom:                Zane C. Bowers
#
# $FreeBSD$
#

PORTNAME=	shell-include
PORTVERSION=	0.1.2
CATEGORIES=	shells devel
MASTER_SITES=	http://vvelox.net/src/shell-include/
EXTRACT_SUFX=	.tgz

MAINTAINER=	vvelox@vvelox.net
COMMENT=	A include system for shell scripts

USE_PERL5=	yes

MAN3=		random::shortIntRandom.3 \
		random.3 \
		fileGetLine.3

MAN7=		shell-include.7

WRKSRC=		${WRKDIR}/${DISTNAME}

#nothing to configure
do-configure:
	@${ECHO} -n

#nothing to build
do-build:
	@${ECHO} -n

do-install:
	@${EXEC} cd ${WRKSRC}/ ; ${WRKSRC}/install ${PREFIX}

.include <bsd.port.mk>
