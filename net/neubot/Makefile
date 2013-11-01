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

USE_PYTHON=	2.5-2.9

NO_BUILD=	yes

USERS=		_neubot
GROUPS=		_neubot
LSTATEDIR=	/var
STATEDIR=	${LSTATEDIR}/${PORTNAME}
MAKE_ENV=	LOCALSTATEDIR=${LSTATEDIR} MANDIR=${MANPREFIX}/man

USE_RC_SUBR=	neubotd
INSTALLS_ICONS=	yes

DOCS=		AUTHORS BUGS ChangeLog PRIVACY README.rst TODO

SUB_FILES=	pkg_message
SUB_LIST+=	PYTHON_CMD=${PYTHON_CMD}
PKGMESSAGE=	${WRKDIR}/pkg_message

post-install:
	${RM} -rf ${STAGEDIR}${LSTATEDIR}
	(cd ${STAGEDIR}${PREFIX} \
	&& ${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py \
	-d ${PREFIX} -f ${DATADIR:S;${PREFIX}/;;})
.if !defined(NOPORTDOCS)
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
