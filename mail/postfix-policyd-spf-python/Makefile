# Created by: Giel van Schijndel <me@mortis.eu>
# $FreeBSD$

PORTNAME=	postfix-policyd-spf-python
PORTVERSION=	2.0.2
PORTREVISION=	1
CATEGORIES=	mail python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pypolicyd-spf-${PORTVERSION}

MAINTAINER=	yasu@utahime.org
COMMENT=	Pure Python Postfix policy daemon for SPF checking

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	Use mail/py-spf-engine instead (Project is superseded by successor)
EXPIRATION_DATE=	2020-08-31

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyspf>0:mail/py-pyspf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}authres>0:mail/py-authres@${PY_FLAVOR}

USES=		python:3.3+
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

CONFLICTS=	py*-spf-engine

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
