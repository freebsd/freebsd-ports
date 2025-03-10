PORTNAME=	docbook-to-man
PORTVERSION=	1.0
PORTREVISION=	4
CATEGORIES=	textproc
MASTER_SITES=	https://www.oasis-open.org/docbook/tools/dtm/
DISTNAME=	docbook-to-man

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	DocBook SGML DTD into nroff/troff -man macros converter
WWW=		https://www.oasis-open.org/docbook/tools/dtm/

LICENSE=	MIT

RUN_DEPENDS=	docbook>=0:textproc/docbook \
		openjade>=0:textproc/openjade

USES=		imake

MAKE_JOBS_UNSAFE=	yes

post-extract:
	@${MV} ${WRKSRC}/Doc/instant.1 ${WRKSRC}/Instant/oinstant.man

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|' ${WRKSRC}/cmd/docbook-to-man.sh

.include <bsd.port.mk>
