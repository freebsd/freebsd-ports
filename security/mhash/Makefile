# New ports collection makefile for:	mhash
# Version required:	0.5.0
# Date created:		Mon Jun 28 17:59:13 PDT 1999
# Whom:			nsayer@freebsd.org
#
# $FreeBSD$
#

DISTNAME=	mhash-0.5.0
CATEGORIES=	security
MASTER_SITES=	http://sasweb.de/mhash/data/

MAINTAINER=	nsayer@freebsd.org

GNU_CONFIGURE=	yes
CONFIGURE_ARGS= --prefix=${PREFIX} --disable-pthreads

MAN3=		mhash.3

RESTRICTED=	"yes - cryptography"

post-install:
	@${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
