# New ports collection makefile for:	titlefix
# Date created:		17 August 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	titlefix
PORTVERSION=	0.5.3
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Renames files in a proper English title format

RUN_DEPENDS=	id3v2:${PORTSDIR}/audio/id3v2

USE_PERL5_RUN=	yes
NO_BUILD=	yes
MAN1=		titlefix.1 titlefixid3.1 titleid3.1
PLIST_FILES=	bin/titlefix bin/titlefixid3 bin/titleid3

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/
	@${LN} -sf ${PREFIX}/bin/${PORTNAME} ${PREFIX}/bin/titlefixid3
	@${LN} -sf ${PREFIX}/bin/${PORTNAME} ${PREFIX}/bin/titleid3
	@${INSTALL_MAN} ${MAN1:S,^,${WRKSRC}/man1/,} ${MAN1PREFIX}/man/man1/
.include <bsd.port.mk>
