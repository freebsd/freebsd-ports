# New ports collection makefile for:	mhash
# Date created:		Mon Jun 28 17:59:13 PDT 1999
# Whom:			nsayer@freebsd.org
#
# $FreeBSD$
#

PORTNAME=	mhash
PORTVERSION=	0.6.1
CATEGORIES=	security
MASTER_SITES=	http://schumann.cx/mhash/dl/

MAINTAINER=	nsayer@freebsd.org

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+= --with-LDFLAGS='-lc_r'

MAN3=		mhash.3

post-install:
	@${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
