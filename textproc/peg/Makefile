PORTNAME=	peg
DISTVERSION=	0.1.18
CATEGORIES=	textproc
MASTER_SITES=	https://www.piumarta.com/software/peg/

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	Recursive-descent parser generators for C

LICENSE=	MIT

USES=		gmake

PLIST_FILES=	bin/leg \
		bin/peg \
		man/man1/peg.1.gz

post-patch:
	@${REINPLACE_CMD} -e 's,%%STAGEDIR%%,${STAGEDIR},g' \
		-e 's,%%PREFIX%%,${PREFIX},g' ${WRKSRC}/Makefile

.include <bsd.port.mk>
