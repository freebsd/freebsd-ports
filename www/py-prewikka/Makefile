# New ports collection makefile for:	prewikka
# Date created:				2006-03-13
# Whom:					Robin Gruyters <r.gruyters@yirdis.nl>
#
# $FreeBSD$
#

PORTNAME=	prewikka
PORTVERSION=	0.9.14
PORTREVISION=	4
CATEGORIES=	www security python
MASTER_SITES=	http://www.prelude-ids.org/download/releases/ \
		http://www.prelude-ids.org/download/releases/old/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Frontend for the Prelude IDS

BUILD_DEPENDS=	cheetah-compile:${PORTSDIR}/devel/py-cheetah
LIB_DEPENDS=	prelude.20:${PORTSDIR}/security/libprelude \
		preludedb.4:${PORTSDIR}/security/libpreludedb

USE_PYTHON=		2.3+
USE_PYDISTUTILS=	yes

.if !defined(WITHOUT_NLS)
USE_GETTEXT=		yes
PLIST_SUB+=		NLS=""
.else
PLIST_SUB+=		NLS="@comment "
.endif

post-patch:
	${MV} ${WRKSRC}/conf/prewikka.conf ${WRKSRC}/conf/prewikka.conf-dist
	${REINPLACE_CMD} 's,conf/prewikka.conf,conf/prewikka.conf-dist,' \
	   ${WRKSRC}/setup.py
.if defined(WITHOUT_NLS)
	${REINPLACE_CMD} 's,\(.*self.data_files.extend(self._compile_po_files())\),#\1,' \
	   ${WRKSRC}/setup.py
.endif

post-install:
	@if [ ! -f ${PREFIX}/etc/prewikka/prewikka.conf ]; then \
	   ${CP} -p ${PREFIX}/etc/prewikka/prewikka.conf-dist \
	      ${PREFIX}/etc/prewikka/prewikka.conf ; \
	fi

.include <bsd.port.mk>
