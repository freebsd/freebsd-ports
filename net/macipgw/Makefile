# Ports collection makefile for:    macipgw
# Version required:     macipgw-1.0
# Date created:         25 Nov 1997
# Whom:                 stb
#
# $Id: Makefile,v 1.2 1997/12/09 05:20:18 asami Exp $
#

DISTNAME=       macipgw-1.0
CATEGORIES=	net
MASTER_SITES=   ftp://ftp.promo.de/pub/people/stefan/netatalk/	\
		ftp://ftp.hanse.de/pub/people/stefan.bethke/netatalk/ \
		http://www.freebsd.org/~stb/netatalk/

MAINTAINER=	stb@freebsd.org

BUILD_DEPENDS=	${PREFIX}/lib/libatalk.a:${PORTSDIR}/net/netatalk \
		${PREFIX}/include/atalk/ddp.h:${PORTSDIR}/net/netatalk
RUN_DEPENDS=	${PREFIX}/libexec/atalkd:${PORTSDIR}/net/netatalk

.include <bsd.port.mk>
