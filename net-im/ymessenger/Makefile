# ex:ts=8
# Ports collection makefile for:  yahoo-messenger
# Date created:			  Sat Dec 16, 2000
# Whom:				  David O'Brien (obrien@NUXI.com)
#
# $FreeBSD$
#

PORTNAME=	ymessenger
PORTVERSION=	1.0.4
PORTEPOCH=	20020902
CATEGORIES=	net
MASTER_SITES=	http://download.yahoo.com/dl/unix/
DISTNAME=	fbsd4.${PORTNAME}
EXTRACT_SUFX=	.tgz

BROKEN=		"Dumps core immediately when invoked on 5.x"

MAINTAINER=	sethk@meowfishies.com
COMMENT=	Yahoo! Messenger - Instant messaging client

LIB_DEPENDS=	gdk_pixbuf.2:${PORTSDIR}/graphics/gdk-pixbuf

USE_GNOME=	gtk12
USE_REINPLACE=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500000
LIB_DEPENDS+=    c.4:${PORTSDIR}/misc/compat4x
.endif

ONLY_FOR_ARCHS=	i386

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
	${INSTALL_DATA} ${WRKDIR}/lib/libgtkhtml.so.0 \
		${PREFIX}/lib/ymessenger/

post-patch:
	${REINPLACE_CMD} -e 's:%%PREFIX%%:${PREFIX}:g' ${WRKDIR}/bin/ymessenger

.include <bsd.port.post.mk>
