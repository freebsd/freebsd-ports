# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	byobu
PORTVERSION=	5.127
CATEGORIES=	sysutils
MASTER_SITES=	http://launchpad.net/${PORTNAME}/trunk/${PORTVERSION}/+download/
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

MAINTAINER=	jcoffman@openfire.io
COMMENT=	Profile and configuration utilities for GNU Screen

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	screen:sysutils/screen \
		bash:shells/bash

USES=		autoreconf python shebangfix

SHEBANG_FILES=	usr/lib/byobu/include/notify_osd \
		usr/lib/byobu/include/config.py.in \
		usr/lib/byobu/include/select-session.py

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	DOCS

NO_ARCH=	yes

post-patch:
	${FIND} ${WRKSRC} -type f | ${XARGS} \
		${REINPLACE_CMD} \
			-e "s@/bin/bash@${LOCALBASE}/bin/bash@" \
			-e "s@/usr/bin/python@${PYTHON_CMD}@"
	${REINPLACE_CMD} -e 's,@sysconfdir@/profile.d,$$(datadir)/@PACKAGE@,' \
		${WRKSRC}/etc/profile.d/Makefile.am
	${FIND} ${WRKSRC}/usr/lib/byobu -type f -maxdepth 1 | ${XARGS} \
		${REINPLACE_CMD} -e 's:/proc:/compat/linux/proc:g'

.include <bsd.port.mk>
