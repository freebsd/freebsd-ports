# ex:ts=8
# New ports collection makefile for:	fwlogwatch
# Date created:			Nov 20, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	fwlogwatch
PORTVERSION=	0.9.3
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://www.kybs.de/boris/sw/

MAINTAINER=	jim@corebsd.or.id
COMMENT=	A packet filter and firewall log analyzer

LIB_DEPENDS=	intl.5:${PORTSDIR}/devel/gettext-old

USE_BZIP2=	yes
USE_REINPLACE=	yes
MAKE_ENV=	MKDIR="${MKDIR}"
INSTALL_TARGET=	install install-config install-i18n

MAN8=	fwlogwatch.8

post-patch:
	@${REINPLACE_CMD} -e "s,/etc,${PREFIX}/etc,g" ${WRKSRC}/${MAN8}

post-install:
	@${INSTALL_SCRIPT} ${FILESDIR}/fwlogwatch.sh.sample ${PREFIX}/etc/rc.d

.include <bsd.port.mk>
