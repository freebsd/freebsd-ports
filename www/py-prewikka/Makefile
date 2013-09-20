# Created by: Robin Gruyters <r.gruyters@yirdis.nl>
# $FreeBSD$

PORTNAME=	prewikka
PORTVERSION=	1.0.1p1
CATEGORIES=	www security python
MASTER_SITES=	https://www.prelude-ids.org/attachments/download/286/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Frontend for the Prelude IDS

BUILD_DEPENDS=	cheetah-compile:${PORTSDIR}/devel/py-cheetah
LIB_DEPENDS=	prelude:${PORTSDIR}/security/libprelude \
		preludedb:${PORTSDIR}/security/libpreludedb

USE_PYTHON=		-2.7
USE_PYDISTUTILS=	yes

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=		NLS=""
.else
PLIST_SUB+=		NLS="@comment "
.endif

post-patch:
	${MV} ${WRKSRC}/conf/prewikka.conf ${WRKSRC}/conf/prewikka.conf-dist
	${REINPLACE_CMD} 's,conf/prewikka.conf,conf/prewikka.conf-dist,' \
	   ${WRKSRC}/setup.py
.if !${PORT_OPTIONS:MNLS}
	${REINPLACE_CMD} 's,\(.*self.data_files.extend(self._compile_po_files())\),#\1,' \
	   ${WRKSRC}/setup.py
.endif

post-install:
	@if [ ! -f ${PREFIX}/etc/prewikka/prewikka.conf ]; then \
	   ${CP} -p ${PREFIX}/etc/prewikka/prewikka.conf-dist \
	      ${PREFIX}/etc/prewikka/prewikka.conf ; \
	fi

.include <bsd.port.mk>
