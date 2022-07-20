PORTNAME=	docbook-to-man
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	https://www.oasis-open.org/docbook/tools/dtm/
DISTNAME=	${PORTNAME}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	DocBook SGML DTD into nroff/troff -man macros converter

RUN_DEPENDS=	docbook>0:textproc/docbook

USES=		imake

MAKE_JOBS_UNSAFE=	yes

# There are two ports that satisfy the nsgmls requirement.
# Jade is preferred, but OpenJade can be selected if needed.
OPTIONS_DEFINE=	OPENJADE
OPENJADE_DESC=	Use OpenJade SGML/XML/DSSSL toolkit instead of Jade

OPENJADE_RUN_DEPENDS=	onsgmls:textproc/openjade
OPENJADE_RUN_DEPENDS_OFF=	nsgmls:textproc/jade

post-extract:
	@${MV} ${WRKSRC}/Doc/instant.1 ${WRKSRC}/Instant/oinstant.man

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|' ${WRKSRC}/cmd/docbook-to-man.sh

post-patch-OPENJADE-off:
	@${REINPLACE_CMD} -e 's|%%NSGMLS%%|nsgmls|' ${WRKSRC}/cmd/docbook-to-man.sh

post-patch-OPENJADE-on:
	@${REINPLACE_CMD} -e 's|%%NSGMLS%%|onsgmls|' ${WRKSRC}/cmd/docbook-to-man.sh

.include <bsd.port.mk>
