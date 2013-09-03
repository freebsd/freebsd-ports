# Created by: jabley@automagic.org
# $FreeBSD$

PORTNAME=	xml2rfc
PORTVERSION=	2.4.2
CATEGORIES=	textproc
MASTER_SITES=	http://tools.ietf.org/tools/xml2rfc2/cli/

MAINTAINER=	marcus@FreeBSD.org
COMMENT=	A tool to create RFCs and related documents from XML, as per RFC2629

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lxml>=2.2.8:${PORTSDIR}/devel/py-lxml

USE_PYTHON=	yes
USE_PYDISTUTILS=easy_install

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
