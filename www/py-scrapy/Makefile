# New ports collection makefile for:	py-scrapy
# Date created:				10 Jul 2009
# Whom:					Qing Feng <qingfeng@douban.com>
#
# $FreeBSD$
#

PORTNAME=	Scrapy
PORTVERSION=	0.12.0.2542
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	A high level scraping and web crawling framework

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}twisted>=8.2.0:${PORTSDIR}/devel/py-twisted \
		${PYTHON_PKGNAMEPREFIX}lxml>=2.0:${PORTSDIR}/devel/py-lxml
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}twisted>=8.2.0:${PORTSDIR}/devel/py-twisted \
		${PYTHON_PKGNAMEPREFIX}lxml>=2.0:${PORTSDIR}/devel/py-lxml \
		${PYTHON_SITELIBDIR}/_sqlite3.so:${PORTSDIR}/databases/py-sqlite3

USE_PYTHON=	2.6-2.7
USE_PYDISTUTILS=easy_install

OPTIONS=	SSL	"Support HTTPS"			on
OPTIONSFILE=	${PORT_DBDIR}/py-${PORTNAME}/options

.include <bsd.port.pre.mk>

.if defined(WITH_SSL)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/OpenSSL/__init__.py:${PORTSDIR}/security/py-openssl
.endif

.include <bsd.port.post.mk>
