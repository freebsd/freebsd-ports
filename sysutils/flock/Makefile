# New ports collection makefile for:    flock
# Date created:         Nov 1 2002
# Whom:                 Stephen Gunn <csg@fedex.com>, <csg@waterspout.com>
#
# $FreeBSD$
#

PORTNAME=	flock
PORTVERSION=	3.4
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.physics.purdue.edu/pub/pundits/ \
		http://archive.progeny.com/pundits/
DISTNAME=	xapply-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Assert/wait for advisory locks with flock(2)

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

BUILD_DEPENDS=	makeme:${PORTSDIR}/devel/msrc0 \
		mkcmd:${PORTSDIR}/devel/mkcmd

NO_LATEST_LINK=	yes
MAKE_FLAGS=
MAKEFILE=
MAN1=		${PORTNAME}.1
PLIST_FILES=	bin/flock

post-patch:
	@${REINPLACE_CMD} -e 's,CFLAGS=,CFLAGS+=,' -e 's,^DEBUG,#DEBUG,'\
		-e 's,gcc,${CC},' ${WRKSRC}/bin/flock/Make.host

do-build:
	( cd ${WRKSRC}/bin/${PORTNAME} && ${SETENV} ${MAKE_ENV} makeme \
	    ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET} )

do-install:
	( cd ${WRKSRC}/bin/flock && ${SETENV} ${MAKENV} makeme \
	    ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET} )
	${INSTALL_MAN} ${WRKSRC}/bin/${PORTNAME}/${PORTNAME}.man \
	    ${PREFIX}/man/man1/${PORTNAME}.1

.include <bsd.port.mk>
