# New ports collection makefile for:	archmbox
# Date created:			4 April 2004
# Whom:				Talal Al-Dik <tad@vif.com>
#
# $FreeBSD$
#

PORTNAME=	archmbox
PORTVERSION=	4.9.0
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	adc-archmbox

MAINTAINER=	tad@vif.com
COMMENT=	Email archiver written in perl; parses mailboxes and performs actions

GNU_CONFIGURE=	yes
USE_PERL5=	yes
CONFIGURE_ENV+=	PERL=${PERL}

MAN1=		archmbox.1
PLIST_FILES=	bin/archmbox

.include <bsd.port.mk>
