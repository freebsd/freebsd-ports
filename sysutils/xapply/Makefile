# New ports collection makefile for:    xapply
# Date created:         Nov 1 2002
# Whom:                 Stephen Gunn <csg@fedex.com>, <csg@waterspout.com>
#
# $FreeBSD$
#

PORTNAME=	xapply
PORTVERSION=	3.4
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.physics.purdue.edu/pub/pundits/ \
		http://archive.progeny.com/pundits/
EXTRACT_SUFX=	.tgz

MAINTAINER=	csg@fedex.com
COMMENT=	Parallel Execution tool ala xargs/apply

BUILD_DEPENDS=	makeme:${PORTSDIR}/devel/msrc0 \
		mkcmd:${PORTSDIR}/devel/mkcmd

USE_REINPLACE=	yes
MAKE_FLAGS=
MAKEFILE=
MAN1=		xapply.1
PLIST_FILES=	bin/xapply

post-patch:
	@${REINPLACE_CMD} -e 's,CFLAGS=,CFLAGS+=,' -e 's,^DEBUG,#DEBUG,'\
		-e 's,gcc,${CC},' ${WRKSRC}/bin/xapply/Make.host

do-build:
	( cd ${WRKSRC}/bin/${PORTNAME} && ${SETENV} ${MAKE_ENV} makeme \
	    ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET} )

do-install:
	( cd ${WRKSRC}/bin/${PORTNAME} && ${SETENV} ${MAKENV} makeme \
	    ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET} )
	${INSTALL_MAN} ${WRKSRC}/bin/xapply/${PORTNAME}.man \
	    ${PREFIX}/man/man1/${PORTNAME}.1

.include <bsd.port.mk>
