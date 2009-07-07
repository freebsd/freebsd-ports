# New ports collection makefile for:	sniff
# Date created:		7 December 1998
# Whom:			Rick & Samu
#
# $FreeBSD$
#

PORTNAME=		sniff
PORTVERSION=		1.0
CATEGORIES=		security
MASTER_SITES=		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	fenner

MAINTAINER=		ports@FreeBSD.org
COMMENT=		Program to sniff logins and passwords

MAN1=			sniff.1
PLIST_FILES=		sbin/sniff
HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	configure

post-patch:
	@${REINPLACE_CMD} -e 's|PREFIX=|PREFIX?=|g' \
	${WRKSRC}/Makefile.in

.include <bsd.port.mk>
