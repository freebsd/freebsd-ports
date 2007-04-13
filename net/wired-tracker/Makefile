# New ports collection makefile for:	wired-tracker
# Date created:		2006-12-02
# Whom:			trasz <trasz@pin.if.uz.zgora.pl>
#
# $FreeBSD$
#

PORTNAME=	wired-tracker
PORTVERSION=	1.0
CATEGORIES=	net
MASTER_SITES=	http://www.zankasoftware.com/dist/

MAINTAINER=	trasz@freebsd.org
COMMENT=	Wired tracker

# This is an artificial dependancy - net/wired and net/wired-tracker
# use some common files, like wired/etc/resolv.conf.
RUN_DEPENDS=	${LOCALBASE}/sbin/wired:${PORTSDIR}/net/wired

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_RC_SUBR=	trackerd.sh

MAN1=		trackerdctl.1
MAN5=		trackerd.conf.5
MAN8=		trackerd.8

post-install:
	@if [ ! -f ${PREFIX}/wired/etc/trackerd.conf ]; then \
		${CP} -p ${PREFIX}/wired/etc/trackerd.conf.sample ${PREFIX}/wired/etc/trackerd.conf ; \
	fi
	@if [ ! -f ${PREFIX}/wired/categories ]; then \
		${CP} -p ${PREFIX}/wired/categories.sample ${PREFIX}/wired/categories ; \
	fi

.include <bsd.port.mk>
