# Created by: Aldis Berjoza <aldis@bsdroot.lv>
# $FreeBSD$

PORTNAME=	dicewaregen
PORTVERSION=	1.3
CATEGORIES=	security
MASTER_SITES=	http://files.bsdroot.lv/my/FreeBSD/distfiles/
PKGNAMEPREFIX=	p5-

MAINTAINER=	graudeejs@gmail.com
COMMENT=	Simple perl script to generate Diceware dictionaries for passwords

LIB_DEPENDS+=	libaspell.so:textproc/aspell

USES=		perl5
USE_PERL5=	run

PLIST_FILES=	bin/${PORTNAME}

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/dicewaregen-${REV}
REV=		20c777eac1db

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/dicewaregen.pl \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
