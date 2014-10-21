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

LICENSE=	APACHE20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ipaddr>0:${PORTSDIR}/devel/py-ipaddr \
		${PYTHON_PKGNAMEPREFIX}spf>0:${PORTSDIR}/mail/py-spf \
		${PYTHON_PKGNAMEPREFIX}authres>0:${PORTSDIR}/mail/py-authres

USES=		python
USE_PYTHON=	distutils
PYDISTUTILS_PKGNAME=	pypolicyd-spf

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
	@${MV} ${WRKSRC}/policyd-spf.conf ${WRKSRC}/policyd-spf.conf.sample
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

post-install:
	@${INSTALL} -d ${STAGEDIR}/${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
