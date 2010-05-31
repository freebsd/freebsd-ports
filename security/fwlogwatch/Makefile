# ex:ts=8
# New ports collection makefile for:	fwlogwatch
# Date created:			Nov 20, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	fwlogwatch
PORTVERSION=	1.1
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	http://www.kybs.de/boris/sw/

MAINTAINER=	michael@ranner.eu
COMMENT=	A packet filter and firewall log analyzer

USE_GETTEXT=	yes
USE_BZIP2=	yes
MAKE_ENV=	MKDIR="${MKDIR}"
INSTALL_TARGET=	install install-config install-i18n

MAN8=	fwlogwatch.8

post-patch:
	@${REINPLACE_CMD} -e "s,/etc,${PREFIX}/etc,g" ${WRKSRC}/${MAN8}

post-install:
	@${INSTALL_SCRIPT} ${FILESDIR}/fwlogwatch.sh.sample ${PREFIX}/etc/rc.d

.include <bsd.port.mk>
