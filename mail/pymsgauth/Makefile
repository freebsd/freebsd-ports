# New ports collection makefile for:	pymsgauth
# Date created:		12 Aug 2002
# Whom:			Sergei Kolobov <sergei@kolobov.com>
#
# $FreeBSD$
#

PORTNAME=	pymsgauth
PORTVERSION=	2.0.0
CATEGORIES=	mail python
MASTER_SITES=	http://www.qcc.ca/~charlesc/software/pymsgauth/

MAINTAINER=	sergei@kolobov.com

USE_PYTHON=	yes
USE_REINPLACE=	yes

NO_BUILD=	yes

DOCS=		BUGS CHANGELOG COPYING pymsgauth.txt pymsgauth.html

post-patch:
	${REINPLACE_CMD} -e 's,/usr/bin/python,${PYTHON_CMD},' \
	 	${WRKSRC}/pymsgauth-*
	${RM} ${WRKSRC}/pymsgauth-*.bak

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pymsgauth-* ${PYTHON_SITELIBDIR}
	${LN} -sf ${PYTHON_SITELIBDIR}/pymsgauth-* ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/*.py ${PYTHON_SITELIBDIR}

.if !defined(NOPORTDOCS)
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/pymsgauthrc-example ${EXAMPLESDIR}

	${MKDIR} ${DOCSDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

	@${CAT} ${PKGMESSAGE} | ${SED} -e 's,__EXAMPLES__,${EXAMPLESDIR},'
.include <bsd.port.mk>
