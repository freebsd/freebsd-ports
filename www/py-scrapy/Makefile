# New ports collection makefile for:	py-scrapy
# Date created:				10 Jul 2009
# Whom:					Qing Feng <qingfeng@me.com>
#
# $FreeBSD$
#

PORTNAME=	Scrapy
PORTVERSION=	0.10.3
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP \
		http://scrapy.org/releases/${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	qingfeng@me.com
COMMENT=	A high level scraping and web crawling framework

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}twisted>=8.2.0:${PORTSDIR}/devel/py-twisted \
		${PYTHON_PKGNAMEPREFIX}libxml2>=2.7.6:${PORTSDIR}/textproc/py-libxml2
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}twisted>=8.2.0:${PORTSDIR}/devel/py-twisted \
		${PYTHON_PKGNAMEPREFIX}libxml2>=2.7.6:${PORTSDIR}/textproc/py-libxml2 \
		${PYTHON_SITELIBDIR}/_sqlite3.so:${PORTSDIR}/databases/py-sqlite3

USE_PYTHON=	2.5-2.7
USE_PYDISTUTILS=easy_install

OPTIONS=	SSL	"Support HTTPS"			on \
		JSON	"Support (de)serializing JSON"	on
OPTIONSFILE=	${PORT_DBDIR}/py-${PORTNAME}/options

post-extract:
	${REINPLACE_CMD} -e 's#Twisted>=2.5##g' ${WRKSRC}/setup.py

.include <bsd.port.pre.mk>

.if defined(WITH_SSL)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/OpenSSL/__init__.py:${PORTSDIR}/security/py-openssl
.endif

.if defined(WITH_JSON)
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}simplejson>=0:${PORTSDIR}/devel/py-simplejson
.endif

.include <bsd.port.post.mk>
