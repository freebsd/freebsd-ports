# ex:ts=8
# Ports collection makefile for:  yahoo-messenger
# Date created:			  Sat Dec 16, 2000
# Whom:				  David O'Brien (obrien@NUXI.com)
#
# $FreeBSD$
#

PORTNAME=	ymessenger
PORTVERSION=	0.99.19-1
CATEGORIES=	net
MASTER_SITES=	http://download.yahoo.com/dl/unix/fbsd45/
EXTRACT_SUFX=	.tgz

MAINTAINER=	sethk@meowfishies.com

LIB_DEPENDS=	intl.4:${PORTSDIR}/devel/gettext

ONLY_FOR_ARCHS=	i386

USE_GNOMENG=	yes
USE_GNOME=	gtk12
USE_REINPLACE=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/bin/ymessenger ${PREFIX}/bin
	${MKDIR} ${PREFIX}/libexec/ymessenger
	${INSTALL_PROGRAM} ${WRKDIR}/bin/ymessenger.bin \
		${PREFIX}/libexec/ymessenger
	@(set -x; for i in yahoo_gnome.png yahoo_kde.xpm \
		ymessenger.desktop ymessenger.kdelnk; do \
	    ${INSTALL_DATA} ${WRKDIR}/bin/$$i \
		    ${PREFIX}/libexec/ymessenger; \
	    done)
	${MKDIR} ${PREFIX}/lib/ymessenger
	${INSTALL_DATA} ${WRKDIR}/lib/libgtkhtml.so.21 \
		${PREFIX}/lib/ymessenger/

post-patch:
	${REINPLACE_CMD} -e 's:%%PREFIX%%:${PREFIX}:g' ${WRKDIR}/bin/ymessenger

.include <bsd.port.mk>
