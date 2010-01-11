# New ports collection makefile for:	postfix-policyd-spf-python
# Date created:				8 Jan 2010
# Whom:					Giel van Schijndel <me@mortis.eu>
#
# $FreeBSD$
#

PORTNAME=	postfix-policyd-spf-python
PORTVERSION=	0.7.3
CATEGORIES=	mail python
MASTER_SITES=	http://launchpad.net/pypolicyd-spf/0.7/${PORTVERSION}/+download/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pypolicyd-spf-${PORTVERSION}

MAINTAINER=	me@mortis.eu
COMMENT=	Pure Python Postfix policy daemon for SPF checking

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/spf.py:${PORTSDIR}/mail/py-spf

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	python-policyd-spf

# Apparently launchpad seems to depend on redirects for their downloads. So
# ditch the fetch -A flag.
FETCH_ARGS=	-pRr

MAN1=policyd-spf.1
MAN5=policyd-spf.conf.5

PORTDOCS=	CHANGES \
		LICENSE \
		README \
		README.per_user_whitelisting \
		TODO \
		policyd-spf.conf.commented

PKGMESSAGE=	${WRKSRC}/pkg-message

SUB_FILES=	pkg-message
SUB_LIST=	PYTHON_CMD=${PYTHON_CMD}

do-install:
	# Install data to an unused directory to ensure it doesn't pollute the system
	@(cd ${INSTALL_WRKSRC}; ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} ${PYSETUP} ${PYDISTUTILS_INSTALL_TARGET} ${PYDISTUTILS_INSTALLARGS} --install-data ${WRKDIR}/tmp-datadump-dir)
	${INSTALL_MAN} ${WRKSRC}/policyd-spf.1 ${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/policyd-spf.conf.5 ${MANPREFIX}/man/man5
	@${INSTALL} -d ${ETCDIR}/
	${INSTALL_DATA} ${WRKSRC}/policyd-spf.conf ${ETCDIR}/policyd-spf.conf.sample
.if !defined(NOPORTDOCS)
	@${INSTALL} -d ${DOCSDIR}/
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}/
.endif

post-install:
.if !exists(${ETCDIR}/policyd-spf.conf)
	${CP} -p ${ETCDIR}/policyd-spf.conf.sample ${ETCDIR}/policyd-spf.conf
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
