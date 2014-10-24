# Created by: thierry@pompo.net
# $FreeBSD$

PORTNAME=	neubot
PORTVERSION=	0.4.16.9
CATEGORIES=	net
MASTER_SITES=	http://releases.neubot.org/_packages/

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Measures neutrality of your network connection in the background

LICENSE=	GPLv3

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:${PORTSDIR}/databases/py-sqlite3

USES=		python:2
NO_BUILD=	yes

USERS=		_neubot
GROUPS=		_neubot
LSTATEDIR=	/var
STATEDIR=	${LSTATEDIR}/${PORTNAME}
MAKE_ARGS=	PYTHON=${PYTHON_CMD}
MAKE_ENV=	LOCALSTATEDIR=${LSTATEDIR} MANDIR=${MANPREFIX}/man

USE_RC_SUBR=	neubotd
INSTALLS_ICONS=	yes

DOCS=		AUTHORS BUGS ChangeLog PRIVACY README.rst TODO

SUB_FILES=	pkg_message
SUB_LIST+=	PYTHON_CMD=${PYTHON_CMD}
PKGMESSAGE=	${WRKDIR}/pkg_message

OPTIONS_DEFINE=	DOCS

post-install:
	${RM} -rf ${STAGEDIR}${LSTATEDIR}
	(cd ${STAGEDIR}${PREFIX} \
	&& ${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py \
	-d ${PREFIX} -f ${DATADIR:S;${PREFIX}/;;})
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
