# New ports collection makefile for:	libtextcat
# Date created:		Sat 18 nov 2007
# Whom:			thierry@pompo.net
#
# $FreeBSD$
#

PORTNAME=	libtextcat
PORTVERSION=	2.2
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://software.wise-guys.nl/download/

#PATCH_SITES=	http://cvs.fedora.redhat.com/viewcvs/*checkout*/rpms/libtextcat/devel/
#PATCHFILES=	${PORTNAME}-${PORTVERSION}-OOo.patch
#PATCH_DIST_STRIP=	-p1

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Language guessing by N-Gram-Based Text Categorization

USE_AUTOTOOLS=	libtool:22
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

PORTDOCS=	LICENSE README TODO

post-install:
	${INSTALL_DATA} ${WRKSRC}/src/textcat.h ${PREFIX}/include/
	${MKDIR} ${DATADIR}/LM
	@${ECHO_MSG} "Installing language models provided in Gertjan van Noord's TextCat package"
	(cd ${WRKSRC}/langclass/LM &&		\
	${FIND} . -name "*.lm" -exec ${INSTALL_DATA} "{}" "${DATADIR}/LM/{}" \;)
	${INSTALL_DATA} ${WRKSRC}/langclass/conf.txt "${DATADIR}"
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

regression-test:
	(cd ${WRKSRC}/langclass/ &&		\
	for t in `${LS} ShortTexts/*.txt` ; do	\
	${ECHO_MSG} "Analyzing $$t..." ;	\
	../src/testtextcat conf.txt < $$t ;	\
	done)

.include <bsd.port.mk>
