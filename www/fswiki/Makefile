# $FreeBSD$

PORTNAME=	fswiki
PORTVERSION=	3.6.2
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	OSDN/fswiki
DISTNAME=	wiki${PORTVERSION:S|.|_|g}

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	FreeStyle Wiki (perl based wiki clone)

RUN_DEPENDS=	ja-p5-Jcode>=0:japanese/p5-Jcode \
		p5-HTML-Template>=0:www/p5-HTML-Template

USES=		perl5 shebangfix zip
SHEBANG_FILES=	wiki.cgi
NO_BUILD=	yes

post-extract:
	${SED} -e 's|__DATADIR__|${DATADIR}|' ${FILESDIR}/setup.sh \
		>${WRKSRC}/setup.sh

do-install:
	-${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC}; \
	for d in `${FIND} * -type d`; do \
		${MKDIR} ${STAGEDIR}${DATADIR}/$${d}; \
	done
	cd ${WRKSRC}; \
	for i in `${FIND} . -type f | ${GREP} -v .orig`; do \
		${INSTALL_DATA} $${i} ${STAGEDIR}${DATADIR}/$${i}; \
	done
	${INSTALL_SCRIPT} ${WRKSRC}/wiki.cgi ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/setup.sh ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
