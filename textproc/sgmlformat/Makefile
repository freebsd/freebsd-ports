# New ports collection makefile for:	sgmlformat
# Version required:	1.7
# Date created:		July 16, 1997
# Whom:			jfieber
#
# $Id: Makefile,v 1.9 1998/02/21 21:59:37 jfieber Exp $
#

DISTNAME=	sgmlformat-1.7
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

USE_PERL5=	yes

post-install:
	@${CAT} ${PKGDIR}/MESSAGE

.include <bsd.port.mk>
