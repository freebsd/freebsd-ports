# New ports collection makefile for:   drwebd
# Date created:        10.05.2002
# Whom:                Andrey A. Chernov <ache@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=       drwebd
PORTVERSION=    1.0
CATEGORIES=	security
EXTRACT_ONLY=

MAINTAINER=     ache@FreeBSD.org

DESCR=          ${PORTSDIR}/security/drweb/pkg-descr

NO_BUILD=       yes
NO_WRKSUBDIR=   yes

RUN_DEPENDS=    ${LOCALBASE}/drweb/drwebd:${PORTSDIR}/security/drweb

checksum:
	@${DO_NADA}

do-fetch:
	@${DO_NADA}

do-patch:
	${SED} "s#%PREFIX%#${PREFIX}#g" < ${FILESDIR}/drweb-0.sh \
	    > ${WRKSRC}/drweb-0.sh

do-install:
	${INSTALL_DATA} ${WRKSRC}/drweb-0.sh \
	     ${PREFIX}/etc/rc.d/drweb-0.sh-dist
	if [ ! -f ${PREFIX}/etc/rc.d/drweb-0.sh ]; then \
		${INSTALL_SCRIPT} ${WRKSRC}/drweb-0.sh \
		     ${PREFIX}/etc/rc.d/drweb-0.sh; \
	fi

.include <bsd.port.mk>
