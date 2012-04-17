# Ports collection Makefile for:	mail/imaputils
# Date created:				2012-04-08
# Whom:					Mikhail T. (m.tsatsenko@gmail.com)
#
# $FreeBSD$
#

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

OPTIONS=	SSL	"Enable SSL support" off \
		UNICODE	"Adds unicode support" off

.include <bsd.port.options.mk>

.if defined(WITH_SSL)
RUN_DEPENDS+=	p5-IO-Socket-SSL>=0:${PORTSDIR}/security/p5-IO-Socket-SSL
.endif

.if defined(WITH_UNICODE)
RUN_DEPENDS+=	p5-Unicode-IMAPUtf7>=0:${PORTSDIR}/converters/p5-Unicode-IMAPUtf7
.endif

.include <bsd.port.mk>
