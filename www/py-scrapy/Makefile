# Created by: Qing Feng <qingfeng@douban.com>
# $FreeBSD$

PORTNAME=	Scrapy
PORTVERSION=	0.16.5
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	High level scraping and web crawling framework

LICENSE=	BSD

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lxml>=2.0:${PORTSDIR}/devel/py-lxml \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:${PORTSDIR}/databases/py-sqlite3 \
		${PYTHON_PKGNAMEPREFIX}w3lib>=1.2:${PORTSDIR}/www/py-w3lib

USE_PYTHON=	2
USES=		twisted:run
USE_PYDISTUTILS=easy_install

OPTIONS_DEFINE=	SSL
OPTIONS_DEFAULT=SSL
OPTIONSFILE=	${PORT_DBDIR}/py-${PORTNAME}/options

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSSL}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}openssl>0:${PORTSDIR}/security/py-openssl
.endif

.include <bsd.port.mk>
