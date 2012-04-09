# Ports collection Makefile for:	mail/imaputils
# Date created:				2012-04-08
# Whom:					Mikhail T. (m.tsatsenko@gmail.com)
#
# $FreeBSD$
#

PORTNAME=	imaputils
PORTVERSION=	1.0.0
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	m.tsatsenko@gmail.com
COMMENT=	A number of tools and scripts for use with IMAP servers

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/license.txt

USE_PERL5_RUN=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

post-patch:
	${REINPLACE_CMD} \
		-e 's|/usr/bin/perl|${PERL}|g' ${WRKSRC}/*.pl

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/*.pl ${PREFIX}/bin

.include <bsd.port.mk>
