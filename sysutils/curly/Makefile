# Created by: Stephen Gunn <csg@fedex.com>, <csg@waterspout.com>
# $FreeBSD$

PORTNAME=	curly
PORTVERSION=	3.4
CATEGORIES=	sysutils
MASTER_SITES=   ftp://ftp.physics.purdue.edu/pub/pundits/ \
		http://www.komquats.com/distfiles/ \
		http://people.freebsd.org/~cy/distfiles/

DISTNAME=	xapply-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	cy@FreeBSD.org
COMMENT=	Generalize listed filenames to csh-extended glob patterns

BUILD_DEPENDS=	makeme:devel/msrc0 \
		mkcmd:devel/mkcmd

MAKE_FLAGS=
MAKEFILE=

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
	    ${STAGEDIR}${PREFIX}/man/man1/${PORTNAME}.1
	${LN} -s ${PREFIX}/man/man1/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/man/man1/un${PORTNAME}.1

.include <bsd.port.mk>
