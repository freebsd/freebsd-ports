# Created by: Mikhail T. (m.tsatsenko@gmail.com)
# $FreeBSD$

PORTNAME=	imaputils
DISTVERSION=	1.0.5
CATEGORIES=	mail

MAINTAINER=	m.tsatsenko@gmail.com
COMMENT=	Number of tools and scripts for use with IMAP servers

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		perl5 shebangfix

USE_GITHUB=	yes
GH_ACCOUNT=	mtsatsenko

USE_PERL5=	configure
NO_BUILD=	yes
SHEBANG_FILES=	bin/*

OPTIONS_DEFINE=	SSL UNICODE

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSSL}
RUN_DEPENDS+=	p5-IO-Socket-SSL>=0:security/p5-IO-Socket-SSL
.endif

.if ${PORT_OPTIONS:MUNICODE}
RUN_DEPENDS+=	p5-Unicode-IMAPUtf7>=0:converters/p5-Unicode-IMAPUtf7
.endif

.include <bsd.port.mk>
