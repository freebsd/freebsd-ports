# New ports collection makefile for:	sgmlformat
# Date created:		July 16, 1997
# Whom:			jfieber
#
# $FreeBSD$
#

PORTNAME=	sgmlformat
PORTVERSION=	1.7
PORTREVISION=	2
CATEGORIES=	textproc print
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	kuriyama
#MASTER_SITES=	http://fallout.campusview.indiana.edu/ports/distfiles/

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Generates groff and HTML from linuxdoc and docbook SGML documents

# There are two ports that satisfy the nsgmls requirement.
# Jade is preferred, but it currently doesn't compile on 2.1.x
# system, so use sp in that case.

.include <bsd.port.pre.mk>

.if ${MACHINE_ARCH} != "i386"
WITH_OPENJADE=	yes
.endif

.if ${OSVERSION} < 220000
RUN_DEPENDS=	nsgmls:${PORTSDIR}/textproc/sp
.elif defined(WITH_OPENJADE)
RUN_DEPENDS=	onsgmls:${PORTSDIR}/textproc/openjade
.else
RUN_DEPENDS=	nsgmls:${PORTSDIR}/textproc/jade
.endif
RUN_DEPENDS+=	${PREFIX}/share/sgml/linuxdoc:${PORTSDIR}/textproc/linuxdoc \
		${PREFIX}/share/sgml/docbook:${PORTSDIR}/textproc/docbook

USE_PERL5_RUN=	yes

MAN1=		instant.1 sgmlfmt.1
MAN5=		transpec.5
MANCOMPRESSED=	yes

.if defined(WITH_OPENJADE)
post-patch:
	@${REINPLACE_CMD} -e 's,nsgmls,onsgmls,g' ${WRKSRC}/sgmlfmt/sgmlfmt.pl
	@${REINPLACE_CMD} -e 's,nsgmls,onsgmls,g' ${WRKSRC}/instant/traninit.c
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
