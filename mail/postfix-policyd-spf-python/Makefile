# Created by: Giel van Schijndel <me@mortis.eu>
# $FreeBSD$

PORTNAME=	postfix-policyd-spf-python
PORTVERSION=	1.2
CATEGORIES=	mail python
MASTER_SITES=	https://launchpadlibrarian.net/145855789/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pypolicyd-spf-${PORTVERSION}

MAINTAINER=	me@mortis.eu
COMMENT=	Pure Python Postfix policy daemon for SPF checking

LICENSE=	AL2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ipaddr>0:${PORTSDIR}/devel/py-ipaddr \
		${PYTHON_PKGNAMEPREFIX}spf>0:${PORTSDIR}/mail/py-spf \
		${PYTHON_PKGNAMEPREFIX}authres>0:${PORTSDIR}/mail/py-authres

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	pypolicyd-spf

MAN1=		policyd-spf.1
MAN5=		policyd-spf.conf.5 \
		policyd-spf.peruser.5

PORTDOCS=	CHANGES \
		COPYING \
		README \
		README.per_user_whitelisting \
		policyd-spf.conf.commented

PKGMESSAGE=	${WRKSRC}/pkg-message

SUB_FILES=	pkg-message
SUB_LIST=	PYTHON_CMD=${PYTHON_CMD}

OPTIONS_DEFINE=	DOCS
OPTIONSFILE=	${PORT_DBDIR}/py-${PORTNAME}/options

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e '\/etc/s|/etc|etc|' ${WRKSRC}/setup.py
	@${REINPLACE_CMD} -e "s|/etc/python-policyd-spf/|${PREFIX}/etc/postfix-policyd-spf-python/|" \
		${WRKSRC}/policyd-spf
	@${REINPLACE_CMD} -e "s|/etc/policyd-spf/|${PREFIX}/etc/postfix-policyd-spf-python/|" \
		-e "s|/usr/bin/policyd-spf|${PREFIX}/bin/policyd-spf|" \
		-e "s|/etc/postfix/|${LOCALBASE}/etc/postfix/|" ${WRKSRC}/policyd-spf.1
	@${REINPLACE_CMD} -e "s|/etc/policyd-spf/|${PREFIX}/etc/postfix-policyd-spf-python/|" \
		${WRKSRC}/policyd-spf.conf.5
	@${REINPLACE_CMD} -e "s|/etc/policyd-spf/|${PREFIX}/etc/postfix-policyd-spf-python/|" \
		-e "s|/etc/pypolicyd-spf/|${PREFIX}/etc/postfix-policyd-spf-python/|" \
		${WRKSRC}/policyd-spf.peruser.5

do-install:
	@# Install data to an unused directory to ensure it doesn't pollute the system
	@(cd ${INSTALL_WRKSRC}; ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} ${PYSETUP} \
		${PYDISTUTILS_INSTALL_TARGET} ${PYDISTUTILS_INSTALLARGS} \
		--install-data ${WRKDIR}/tmp-datadump-dir)
	${INSTALL_MAN} ${WRKSRC}/policyd-spf.1 ${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/policyd-spf.conf.5 ${MANPREFIX}/man/man5
	${INSTALL_MAN} ${WRKSRC}/policyd-spf.peruser.5 ${MANPREFIX}/man/man5
	@${INSTALL} -d ${ETCDIR}/
	${INSTALL_DATA} ${WRKSRC}/policyd-spf.conf ${ETCDIR}/policyd-spf.conf.sample
.if ${PORT_OPTIONS:MDOCS}
	@${INSTALL} -d ${DOCSDIR}/
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}/
.endif

post-install:
.if !exists(${ETCDIR}/policyd-spf.conf)
	${CP} -p ${ETCDIR}/policyd-spf.conf.sample ${ETCDIR}/policyd-spf.conf
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
