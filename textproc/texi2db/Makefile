# ex:ts=8
# New ports collection makefile for:	texi2db
# Date created:			May 27, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	texi2db
PORTVERSION=	0.5
CATEGORIES=	textproc
MASTER_SITES=	http://www.tldp.org/downloads/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Converts a Texinfo file into DocBook XML

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/HTML/Entities.pm:${PORTSDIR}/www/p5-HTML-Parser
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=		texi2db.1
PLIST_FILES=	bin/texi2db \
		${SITE_PERL_REL}/${PERL_ARCH}/auto/texi2db/.packlist
PLIST_DIRS=	${SITE_PERL_REL}/${PERL_ARCH}/auto/texi2db

.include <bsd.port.mk>
