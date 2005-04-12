# New ports collection makefile for:	gnupg-devel
# Date created:		5 Oct 2001
# Whom:			Cyrille Lefevre <clefevre@citeweb.net>
#
# $FreeBSD$
#

PORTNAME=	docbook-to-man
PORTVERSION=	1.0
CATEGORIES=	textproc
MASTER_SITES=	http://www.oasis-open.org/docbook/tools/dtm/
DISTNAME=	${PORTNAME}

MAINTAINER=	cyrille.lefevre@laposte.net
COMMENT=	A DocBook SGML DTD into nroff/troff -man macros converter

.include <bsd.port.pre.mk>

# Global variables
#

# There are two ports that satisfy the nsgmls requirement.
# Jade is preferred, but it currently doesn't compile on 2.1.x
# system, so use sp in that case.

.if ${MACHINE_ARCH} == "alpha"
WITH_OPENJADE=	yes
.endif

.if ${OSVERSION} < 220000
RUN_DEPENDS=	nsgmls:${PORTSDIR}/textproc/sp
.elif defined(WITH_OPENJADE)
RUN_DEPENDS=	onsgmls:${PORTSDIR}/textproc/openjade
.else
RUN_DEPENDS=	nsgmls:${PORTSDIR}/textproc/jade
.endif
RUN_DEPENDS+=	${LOCALBASE}/share/sgml/docbook:${PORTSDIR}/textproc/docbook

USE_REINPLACE=	yes
USE_IMAKE=	yes
PREFIX?=	${LOCALBASE}
USE_XLIB=	yes
XFREE86_HTML_MAN= no

MAN1=	oinstant.1

# Local variables
#

.if defined(WITH_OPENJADE)
NSGMLS=		onsgmls
.else
NSGMLS=		nsgmls
.endif

# Post extract
#

post-extract: move-instant.1

move-instant.1:
	@${MV} ${WRKSRC}/Doc/instant.1 ${WRKSRC}/Instant/oinstant.man

# Post patch
#

post-patch: patch-docbook-to-man

patch-docbook-to-man:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|;s|%%NSGMLS%%|${NSGMLS}|' \
		${WRKSRC}/cmd/docbook-to-man.sh

.include <bsd.port.post.mk>
