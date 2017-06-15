# Created by: Aldis Berjoza <aldis@bsdroot.lv>
# $FreeBSD$

PORTNAME=	dicewaregen
PORTVERSION=	1.4
CATEGORIES=	security
PKGNAMEPREFIX=	p5-

MAINTAINER=	graudeejs@gmail.com
COMMENT=	Perl script to generate Diceware dictionaries for passwords

USE_GITHUB=	yes
GH_ACCOUNT=	graudeejs
GH_PROJECT=	dicewaregen.pl

LIB_DEPENDS+=	libaspell.so:textproc/aspell
RUN_DEPENDS+=	p5-List-MoreUtils>=0:lang/p5-List-MoreUtils

USES=		perl5
USE_PERL5=	run

PLIST_FILES=	bin/${PORTNAME}

NO_ARCH=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/dicewaregen.pl \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
