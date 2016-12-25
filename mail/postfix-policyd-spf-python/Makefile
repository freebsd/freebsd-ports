# Created by: Giel van Schijndel <me@mortis.eu>
# $FreeBSD$

PORTNAME=	postfix-policyd-spf-python
PORTVERSION=	1.3.2
PORTREVISION=	1
CATEGORIES=	mail python
MASTER_SITES=	https://launchpad.net/pypolicyd-spf/${PORTVERSION:R}/${PORTVERSION}/+download/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pypolicyd-spf-${PORTVERSION}

MAINTAINER=	me@mortis.eu
COMMENT=	Pure Python Postfix policy daemon for SPF checking

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ipaddr>0:devel/py-ipaddr \
		${PYTHON_PKGNAMEPREFIX}pyspf>0:mail/py-pyspf \
		${PYTHON_PKGNAMEPREFIX}authres>0:mail/py-authres

USES=		python:2.7+
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

PORTDOCS=	CHANGES \
		README \
		README.per_user_whitelisting \
		policyd-spf.conf.commented

PKGMESSAGE=	${WRKSRC}/pkg-message

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	DOCS

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

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}/${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
