# New ports collection makefile for:	prewikka
# Date created:				2006-03-13
# Whom:					Robin Gruyters <r.gruyters@yirdis.nl>
#
# $FreeBSD$
#

PORTNAME=	prewikka
PORTVERSION=	0.9.5
CATEGORIES=	www security python
MASTER_SITES=	http://www.prelude-ids.org/download/releases/ \
		http://www.prelude-ids.org/download/releases/old/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	r.gruyters@yirdis.nl
COMMENT=	Frontend for the Prelude IDS

BUILD_DEPENDS=	cheetah-compile:${PORTSDIR}/devel/py-cheetah
LIB_DEPENDS=	prelude.[6-?]:${PORTSDIR}/security/libprelude \
		preludedb.3:${PORTSDIR}/security/libpreludedb

USE_PYTHON=		2.3+
USE_PYDISTUTILS=	yes

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/bin/env python,${PYTHON_CMD},' \
		${WRKSRC}/cgi-bin/prewikka.cgi

.include <bsd.port.mk>
