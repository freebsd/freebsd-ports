# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	byobu
PORTVERSION=	5.119
CATEGORIES=	sysutils
MASTER_SITES=	http://launchpad.net/${PORTNAME}/trunk/${PORTVERSION}/+download/
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

MAINTAINER=	amutu@amutu.com
COMMENT=	Profile and configuration utilities for GNU Screen

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	screen:sysutils/screen \
		bash:shells/bash

GNU_CONFIGURE=	yes
USES=		autoreconf python shebangfix
SHEBANG_FILES=	usr/lib/byobu/include/notify_osd
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

OPTIONS_DEFINE=	DOCS

NO_ARCH=	yes

post-patch:
	${FIND} ${WRKSRC} -type f | ${XARGS} \
		${REINPLACE_CMD} \
			-e "s@/bin/bash@${LOCALBASE}/bin/bash@" \
			-e "s@/usr/bin/python@${PYTHON_CMD}@"
	${REINPLACE_CMD} -e 's,@sysconfdir@/profile.d,$$(datadir)/@PACKAGE@,' \
		${WRKSRC}/etc/profile.d/Makefile.am

.include <bsd.port.mk>
