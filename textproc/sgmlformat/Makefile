# New ports collection makefile for:	sgmlformat
# Version required:	1.2
# Date created:		July 16, 1997
# Whom:			jfieber
#
# $Id: Makefile,v 1.2 1997/07/19 16:01:56 jfieber Exp $
#

DISTNAME=	sgmlformat-1.2
CATEGORIES=	textproc print
MASTER_SITES=	ftp://fallout.campusview.indiana.edu/pub/sgml/

MAINTAINER=	jfieber@FreeBSD.ORG

# There are two ports that satisfy the nsgmls requirement.
# Jade is preferred, but it currently doesn't compile on 2.1.x
# system, so use sp in that case.
OSVERSION!=	sysctl -n kern.osreldate
.if ${OSVERSION} < 220000
RUN_DEPENDS=	nsgmls:${PORTSDIR}/textproc/sp
.else
RUN_DEPENDS=	nsgmls:${PORTSDIR}/textproc/jade
.endif

RUN_DEPENDS+=	${PREFIX}/share/sgml/linuxdoc:${PORTSDIR}/textproc/linuxdoc \
		${PREFIX}/share/sgml/docbook:${PORTSDIR}/textproc/docbook \
		perl:${PORTSDIR}/lang/perl5

post-install:
	@${CAT} ${PKGDIR}/MESSAGE

.include <bsd.port.mk>
