# New ports collection makefile for:    curly
# Date created:         Nov 1 2002
# Whom:                 Stephen Gunn <csg@fedex.com>, <csg@waterspout.com>
#
# $FreeBSD$
#

PORTNAME=	curly
PORTVERSION=	3.4
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.physics.purdue.edu/pub/pundits/ \
		http://archive.progeny.com/pundits/
DISTNAME=	xapply-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	csg@fedex.com
COMMENT=	Generalize listed filenames to csh-extended glob patterns

BUILD_DEPENDS=	makeme:${PORTSDIR}/devel/msrc0 \
		mkcmd:${PORTSDIR}/devel/mkcmd

USE_REINPLACE=	yes
MAKE_FLAGS=
MAKEFILE=
MAN1=		${PORTNAME}.1
MLINKS=		${PORTNAME}.1 un${PORTNAME}.1

post-patch:
	@${REINPLACE_CMD} -e 's,CFLAGS=,CFLAGS+=,' -e 's,^DEBUG,#DEBUG,'\
		-e 's,gcc,${CC},' ${WRKSRC}/bin/curly/Make.host

do-build:
	( cd ${WRKSRC}/bin/${PORTNAME} && ${SETENV} ${MAKE_ENV} makeme \
	    ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET} )

do-install:
	( cd ${WRKSRC}/bin/curly && ${SETENV} ${MAKENV} makeme \
	    ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET} )
	${INSTALL_MAN} ${WRKSRC}/bin/${PORTNAME}/${PORTNAME}.man \
	    ${PREFIX}/man/man1/${PORTNAME}.1

.include <bsd.port.mk>
