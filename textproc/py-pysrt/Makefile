# Created by: William Grzybowski <wg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pysrt
PORTVERSION=	0.5.0
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wg@FreeBSD.org
COMMENT=	SubRip (.srt) subtitle parser and writer

LICENSE=	GPLv3

USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_AUTOPLIST=	yes

NO_STAGE=	yes

post-patch:
	@${REINPLACE_CMD} 's/="GPLv3",/="GPLv3", zip_safe=False,/' \
		${WRKSRC}/setup.py

.include <bsd.port.mk>
