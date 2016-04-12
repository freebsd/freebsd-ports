# Created by: Cyrille Lefevre <clefevre@citeweb.net>
# $FreeBSD$

PORTNAME=	docbook-to-man
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	http://www.oasis-open.org/docbook/tools/dtm/
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	DocBook SGML DTD into nroff/troff -man macros converter

RUN_DEPENDS=	docbook>0:textproc/docbook

USES=		imake
XFREE86_HTML_MAN=	no

MAKE_JOBS_UNSAFE=	yes

# There are two ports that satisfy the nsgmls requirement.
# Jade is preferred, but OpenJade can be selected if needed.
OPTIONS_DEFINE=	OPENJADE
OPENJADE_DESC=	Use OpenJade SGML/XML/DSSSL toolkit instead of Jade

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MOPENJADE}
RUN_DEPENDS+=	onsgmls:textproc/openjade
NSGMLS=		onsgmls
.else
RUN_DEPENDS+=	nsgmls:textproc/jade
NSGMLS=		nsgmls
.endif

post-extract:
	@${MV} ${WRKSRC}/Doc/instant.1 ${WRKSRC}/Instant/oinstant.man

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}| ; \
		s|%%NSGMLS%%|${NSGMLS}|' ${WRKSRC}/cmd/docbook-to-man.sh

.include <bsd.port.mk>
