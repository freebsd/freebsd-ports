# New ports collection makefile for:	yamcha
# Date created:		                Aug 3, 2006
# Whom:			                Cheng-Lung Sung <clsung@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	yamcha
PORTVERSION=	0.33
CATEGORIES=	textproc science
MASTER_SITES=	http://chasen.org/~taku/software/yamcha/src/

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Yet Another Multipurpose CHunk Annotator

BUILD_DEPENDS=	svm_learn:${PORTSDIR}/science/svmlight

USE_AUTOTOOLS=	libtool:22
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_PERL5_BUILD=yes
DOC_FILES=	feature.png feature2.png feature3.png \
		feature4.png feature5.png index.html \
		yamcha.html yamcha.css

MAN1=		yamcha.1

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
.for doc in ${DOC_FILES}
		${INSTALL_DATA} ${WRKSRC}/doc/${doc} ${DOCSDIR}
.endfor
	@${FIND} -s ${DOCSDIR} -type f | \
		${SED} -e 's|^${PREFIX}/||' >> ${TMPPLIST}
	@${FIND} -s ${DOCSDIR} -type d | \
		${SED} -e 's|^${PREFIX}/|@dirrm |' >> ${TMPPLIST}
.endif

.include <bsd.port.mk>
