# Created by: Daniel Gerzo <danger@FreeBSD.org>
# $FreeBSD$

PORTNAME=	uwsgi
PORTVERSION=	1.9.10
CATEGORIES=	www python
MASTER_SITES=	http://projects.unbit.it/downloads/

MAINTAINER=	demon@FreeBSD.org
COMMENT=	Developer-friendly WSGI server which uses uwsgi protocol

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

MAKE_JOBS_SAFE=	yes

USE_GNOME=	libxml2
USE_PYTHON=	yes
USE_RC_SUBR=	uwsgi

PLIST_FILES=	bin/uwsgi \
		${PYTHONPREFIX_SITELIBDIR}/uwsgidecorators.py

post-patch:
	${REINPLACE_CMD} -e 's|python|${PYTHON_CMD}|' ${WRKSRC}/Makefile

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/
	@${MKDIR} ${PYTHONPREFIX_SITELIBDIR}
	@${INSTALL_DATA}  ${WRKSRC}/uwsgidecorators.py ${PYTHONPREFIX_SITELIBDIR}

.include <bsd.port.mk>
