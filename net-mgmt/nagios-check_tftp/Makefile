# Created by: hr <holgerrepp@googlemail.com>
# $FreeBSD$

PORTNAME=	check_tftp
PORTVERSION=	1.0.1
CATEGORIES=	net-mgmt
MASTER_SITES=	http://mymixrechner.de/freebsd-ports/distfiles/
PKGNAMEPREFIX=	nagios-
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=

MAINTAINER=	holgerrepp@googlemail.com
COMMENT=	Nagios plugin to check tftp servers

RUN_DEPENDS=	bash:shells/bash \
		${LOCALBASE}/bin/tftp:ftp/tftp-hpa

PLIST_FILES=	libexec/nagios/check_tftp

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

post-patch:
	${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' \
		${WRKSRC}/check_tftp

do-extract:
	@${MKDIR} ${WRKSRC}
	@${CP} ${DISTDIR}/${PORTNAME} ${WRKSRC}

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/libexec/nagios
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} \
		${STAGEDIR}${PREFIX}/libexec/nagios

.include <bsd.port.mk>
