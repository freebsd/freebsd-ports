# $FreeBSD$

PORTNAME=	fswiki
PORTVERSION=	3.6.2
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP}
MASTER_SITE_SUBDIR=	fswiki/20797
DISTNAME=	wiki${PORTVERSION:S|.|_|g}

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	FreeStyle Wiki (perl based wiki clone)

RUN_DEPENDS=	ja-p5-Jcode>=0:${PORTSDIR}/japanese/p5-Jcode \
	p5-HTML-Template>=0:${PORTSDIR}/www/p5-HTML-Template

USES=		perl5 zip
NO_BUILD=	yes

NO_STAGE=	yes
post-extract:
	${SED} -e 's|__DATADIR__|${DATADIR}|' ${FILESDIR}/setup.sh \
		>${WRKSRC}/setup.sh

do-install:
	-${MKDIR} ${DATADIR}
	cd ${WRKSRC}; \
	for d in `${FIND} * -type d`; do \
		${MKDIR} ${DATADIR}/$${d}; \
	done
	cd ${WRKSRC}; \
	for i in `${FIND} . -type f | ${GREP} -v .orig`; do \
		${INSTALL_DATA} $${i} ${DATADIR}/$${i}; \
	done
	${INSTALL_SCRIPT} ${WRKSRC}/wiki.cgi ${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/setup.sh ${DATADIR}

.include <bsd.port.mk>
