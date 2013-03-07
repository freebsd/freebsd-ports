# Created by: Mikhail T. (m.tsatsenko@gmail.com)
# $FreeBSD$

PORTNAME=	imaputils
PORTVERSION=	1.0.2
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	m.tsatsenko@gmail.com
COMMENT=	A number of tools and scripts for use with IMAP servers

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/COPYING

USE_PERL5_RUN=	yes
NO_BUILD=	yes
PERL_CONFIGURE=	yes

OPTIONS_DEFINE=	SSL UNICODE

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSSL}
RUN_DEPENDS+=	p5-IO-Socket-SSL>=0:${PORTSDIR}/security/p5-IO-Socket-SSL
.endif

.if ${PORT_OPTIONS:MUNICODE}
RUN_DEPENDS+=	p5-Unicode-IMAPUtf7>=0:${PORTSDIR}/converters/p5-Unicode-IMAPUtf7
.endif

.include <bsd.port.mk>
