# New ports collection makefile for:   ip6_int
# Date created:        22 November 2001
# Whom:                Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=	ip6_int
PORTVERSION=	1.0
CATEGORIES=	net ipv6
MASTER_SITES=	http://www.bieringer.de/linux/IPv6/tools/
DISTNAME=	ip6_int
EXTRACT_SUFX=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	jylefort@FreeBSD.org
COMMENT=	Convert an IPv4/IPv6 address to an in-addr.arpa/ip6.int PTR value

PLIST_FILES=	bin/ip6_int
NO_BUILD=	yes
USE_PERL5=	yes

do-extract:
	@${MKDIR} ${WRKSRC}
	@${CP} ${DISTDIR}/${DISTNAME} ${WRKSRC}

post-patch:
	@${PERL} -pi -e 's,^#!/usr/bin/perl,#!${PERL},' ${WRKSRC}/ip6_int

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/ip6_int ${PREFIX}/bin

.include <bsd.port.mk>
