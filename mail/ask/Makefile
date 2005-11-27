# New ports collection makefile for:	ask
# Date created:				2 November 2005
# Whom:					Marcelo Araujo <araujobsd@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	ask
PORTVERSION=	2.5.0
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	a-s-k

MAINTAINER=	araujobsd@gmail.com
COMMENT=	Anti Spam Killer content filtering

USE_PYTHON=	yes
NO_BUILD=	yes

PLIST_SUB=	VER=${PORTVERSION}

do-install:
	${MKDIR} ${PREFIX}/ask
	${INSTALL_SCRIPT} ${WRKSRC}/COPYING ${PREFIX}/ask
	${INSTALL_SCRIPT} ${WRKSRC}/ChangeLog ${PREFIX}/ask
	${INSTALL_SCRIPT} ${WRKSRC}/TODO ${PREFIX}/ask
	${INSTALL_SCRIPT} ${WRKSRC}/ask.py ${PREFIX}/ask
	${INSTALL_SCRIPT} ${WRKSRC}/askconfig.py ${PREFIX}/ask
	${INSTALL_SCRIPT} ${WRKSRC}/ask-${PORTVERSION}-1.spec ${PREFIX}/ask
	${INSTALL_SCRIPT} ${WRKSRC}/asklock.py ${PREFIX}/ask
	${INSTALL_SCRIPT} ${WRKSRC}/asklog.py ${PREFIX}/ask
	${INSTALL_SCRIPT} ${WRKSRC}/askmail.py ${PREFIX}/ask
	${INSTALL_SCRIPT} ${WRKSRC}/askmain.py ${PREFIX}/ask
	${INSTALL_SCRIPT} ${WRKSRC}/askmessage.py ${PREFIX}/ask
	${INSTALL_SCRIPT} ${WRKSRC}/askremote.py ${PREFIX}/ask
	${INSTALL_SCRIPT} ${WRKSRC}/asksetup.py ${PREFIX}/ask
	${INSTALL_SCRIPT} ${WRKSRC}/askversion.py ${PREFIX}/ask
	${INSTALL_SCRIPT} ${WRKSRC}/test.py ${PREFIX}/ask
	${CP} -R ${WRKSRC}/samples ${PREFIX}/ask
	${CP} -R ${WRKSRC}/templates ${PREFIX}/ask

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${CP} -R ${WRKSRC}/docs ${DOCSDIR}
	${CP} -R ${WRKSRC}/utils ${DOCSDIR}
.endif

.include <bsd.port.mk>
