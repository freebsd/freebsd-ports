# New ports collection makefile for:	cloc
# Date created:		2 May 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cloc
PORTVERSION=	1.08
CATEGORIES=	misc
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/v${PORTVERSION}
EXTRACT_SUFX=	.pl

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Counts lines of code

RUN_DEPENDS=	p5-Algorithm-Diff>=0:${PORTSDIR}/devel/p5-Algorithm-Diff

USE_PERL5_RUN=	yes
EXTRACT_CMD=	${CP}
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	./${PORTNAME}
PLIST_FILES=	bin/${PORTNAME}
NO_BUILD=	yes

do-install:
	@${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin/

.include <bsd.port.mk>
