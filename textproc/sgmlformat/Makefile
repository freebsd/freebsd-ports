# New ports collection makefile for:	sgmlformat
# Version required:	1.7
# Date created:		July 16, 1997
# Whom:			jfieber
#
# $Id: Makefile,v 1.12 1998/11/11 05:37:32 asami Exp $
#

DISTNAME=	sgmlformat-1.7
CATEGORIES=	textproc print
MASTER_SITES=	http://fallout.campusview.indiana.edu/ports/distfiles/

MAINTAINER=	jfieber@FreeBSD.ORG

# There are two ports that satisfy the nsgmls requirement.
# Jade is preferred, but it currently doesn't compile on 2.1.x
# system, so use sp in that case.

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 220000
RUN_DEPENDS=	nsgmls:${PORTSDIR}/textproc/sp
.else
RUN_DEPENDS=	nsgmls:${PORTSDIR}/textproc/jade
.endif

RUN_DEPENDS+=	${PREFIX}/share/sgml/linuxdoc:${PORTSDIR}/textproc/linuxdoc \
		${PREFIX}/share/sgml/docbook:${PORTSDIR}/textproc/docbook \

USE_PERL5=	yes

MAN1=		instant.1 sgmlfmt.1
MAN5=		transpec.5
MANCOMPRESSED=	yes

post-install:
	@${CAT} ${PKGDIR}/MESSAGE

.include <bsd.port.post.mk>
