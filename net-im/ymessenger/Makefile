# ex:ts=8
# Ports collection makefile for:  yahoo-messenger
# Date created:			  Sat Dec 16, 2000
# Whom:				  David O'Brien (obrien@NUXI.com)
#
# $FreeBSD$
#

PORTNAME=	ymessenger
PORTVERSION=	1.0.4
PORTREVISION=	5
PORTEPOCH=	20020902
CATEGORIES=	net-im
MASTER_SITES=	http://public.yahoo.com/~mmk/
DISTNAME=	fbsd5.${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	sethk@meowfishies.com
COMMENT=	Yahoo! Messenger - Instant messaging client

BROKEN=		Dynamically linked binary linked to old version of gtkhtml no longer in ports

USE_GNOME=	gtk12 gdkpixbuf
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 600000
LIB_DEPENDS+=	c.5:${PORTSDIR}/misc/compat5x
.endif

.if ${OSVERSION} < 500000
IGNORE=		does not run on FreeBSD 4.x
.endif

ONLY_FOR_ARCHS=	i386

GETTEXT_MAJOR=	6

post-patch:
	${REINPLACE_CMD} -e 's:%%PREFIX%%:${PREFIX}:g' ${WRKDIR}/bin/ymessenger
	@${CHMOD} +w ${WRKDIR}/share/ymessenger/ymessenger.bin
	${ECHO} ${GETTEXT_MAJOR} | dd bs=1 count=1 conv=notrunc seek=43202 \
		of=${WRKDIR}/share/ymessenger/ymessenger.bin

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/bin/ymessenger ${PREFIX}/bin
	${MKDIR} ${PREFIX}/libexec/ymessenger
	${INSTALL_PROGRAM} ${WRKDIR}/share/ymessenger/ymessenger.bin \
		${PREFIX}/libexec/ymessenger
	@(set -x; for i in yahoo_gnome.png yahoo_kde.xpm \
		ymessenger.desktop ymessenger.kdelnk; do \
	    ${INSTALL_DATA} ${WRKDIR}/share/ymessenger/$$i \
		    ${PREFIX}/libexec/ymessenger; \
	    done)
	${MKDIR} ${PREFIX}/lib/ymessenger
	${INSTALL_DATA} ${WRKDIR}/lib/libgtkhtml.so.6 \
		${PREFIX}/lib/ymessenger/

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
