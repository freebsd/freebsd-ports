# New ports collection makefile for:	icukrell
# Date Created:		2 July 2001
# Whom:			Peter van Heusden <pvh@egenetics.com>
#
# $FreeBSD$
#

PORTNAME=	icukrell
PORTVERSION=	0.1.3
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	pvh@wfeet.za.net

BROKEN=		"Does not compile"

BUILD_DEPENDS=	${X11BASE}/include/gkrellm/gkrellm.h:${PORTSDIR}/sysutils/gkrellm
RUN_DEPENDS=	gkrellm:${PORTSDIR}/sysutils/gkrellm \
		gnomeicu:${PORTSDIR}/net/gnomeicu

USE_X_PREFIX=	yes
USE_GNOMENG=	yes
USE_GNOME=	gnomelibs

post-patch:
	@${PERL} -pi -ne "s!/usr/local/!${PREFIX}/!" ${WRKSRC}/config.h

do-install:
	@${INSTALL} -d -o ${SHAREOWN} -g ${SHAREGRP} -m 755 \
		${PREFIX}/libexec/gkrellm/plugins
	@${INSTALL_DATA} ${WRKSRC}/icukrell.so ${PREFIX}/libexec/gkrellm/plugins
	@${INSTALL_PROGRAM} ${WRKSRC}/icukrell-client ${PREFIX}/bin

.include <bsd.port.mk>
