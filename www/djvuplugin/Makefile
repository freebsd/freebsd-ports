# New ports collection makefile for:   djvuplugin
# Date created:			21 Jul 1999
# Whom:				Mikhail Teterin <mi@aldan.algebra.com>
#
# $FreeBSD$
#

PORTNAME=	djvuplugin
PORTVERSION=	0.9
CATEGORIES=	www graphics
MASTER_SITES=	http://www.djvu.com/products/plugin/unix/
DISTNAME=	npdjvu-freebsd

MAINTAINER=	mi@aldan.algebra.com

RUN_DEPENDS=	netscape:${PORTSDIR}/www/netscape47-communicator

NO_BUILD=	yes
NO_PACKAGE=	"User should read and accept license from AT&T"
NO_CDROM=	${NO_PACKAGE}

do-install:
	@${TAR} -xpf ${WRKSRC}/archive.tar -C ${PREFIX}/lib/netscape
	@${LN} -s ${PREFIX}/lib/netscape/DjVu/dejavu ${PREFIX}/bin

post-install:
	# *******************************************************
	# Please read and agree to the license at:
	# ${PREFIX}/lib/netscape/DjVu/license.html
	# before using this plugin.
	# *******************************************************

.include <bsd.port.mk>
