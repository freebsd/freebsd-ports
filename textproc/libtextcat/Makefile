# New ports collection makefile for:	libtextcat
# Date created:		Sat 18 nov 2007
# Whom:			thierry@pompo.net
#
# $FreeBSD$
#

PORTNAME=	libtextcat
PORTVERSION=	2.2
CATEGORIES=	textproc
MASTER_SITES=	http://software.wise-guys.nl/download/

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Language guessing by N-Gram-Based Text Categorization

USE_AUTOTOOLS=	libtool:15
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
USE_LDCONFIG=	yes

PORTDOCS=	LICENSE README TODO

post-install:
	${INSTALL_DATA} ${WRKSRC}/src/textcat.h ${PREFIX}/include/
	${MKDIR} ${DATADIR}/LM
	@${ECHO_MSG} "Installing language models provided in Gertjan van Noord's TextCat package"
	(cd ${WRKSRC}/langclass/LM &&		\
	${FIND} . -name "*.lm" -exec ${INSTALL_DATA} "{}" "${DATADIR}/LM/{}" \;)
	${INSTALL_DATA} ${WRKSRC}/langclass/conf.txt "${DATADIR}"
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}

regression-test:
	(cd ${WRKSRC}/langclass/ &&		\
	for t in `${LS} ShortTexts/*.txt` ; do	\
	${ECHO_MSG} "Analyzing $$t..." ;	\
	../src/testtextcat conf.txt < $$t ;	\
	done)

.include <bsd.port.mk>
