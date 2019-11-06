# Created by: Hakisho Nukama <Nukama@gmail.com>
# $FreeBSD$

PORTNAME=	texcount
PORTVERSION=	2.3
CATEGORIES=	textproc perl5
MASTER_SITES=	TEX_CTAN/support
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}

MAINTAINER=	nukama+maintainer@gmail.com
COMMENT=	Perl module for LaTeX statistics

BROKEN=		unfetchable

#LICENSE=	LPPL13c

NO_BUILD=	yes

USES=		perl5 zip
USE_PERL5=	run

PLIST_FILES+=	bin/texcount

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/texcount.pl \
		${STAGEDIR}${PREFIX}/bin/texcount

.include <bsd.port.mk>
