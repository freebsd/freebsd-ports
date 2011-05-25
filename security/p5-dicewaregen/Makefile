# New ports collection makefile for:	p5-dicewaregen
# Date created:				2011.05.22
# Whom:					Aldis Berjoza <aldis@bsdroot.lv>
#
# $FreeBSD$
#

PORTNAME=	dicewaregen
PORTVERSION=	1.3
CATEGORIES=	security
MASTER_SITES=	http://files.bsdroot.lv/my/FreeBSD/distfiles/
PKGNAMEPREFIX=	p5-

MAINTAINER=	aldis@bsdroot.lv
COMMENT=	A simple perl script to generate Diceware dictionaries for passwords

LIB_DEPENDS+=	aspell:${PORTSDIR}/textproc/aspell

USE_PERL5_RUN=	5.8.8+

PLIST_FILES=	bin/${PORTNAME}

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/dicewaregen-${REV}
REV=		20c777eac1db

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/dicewaregen.pl ${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
