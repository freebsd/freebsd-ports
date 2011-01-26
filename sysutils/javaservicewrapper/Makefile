# New ports collection makefile for:	javaservicewrapper
# Date created:				2007-09-13
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	javaservicewrapper
PORTVERSION=	3.5.7
CATEGORIES=	sysutils java
MASTER_SITES=	http://wrapper.tanukisoftware.com/download/${PORTVERSION}/
DISTNAME=	wrapper_${PORTVERSION}_src

MAINTAINER=	mike.jakubik@gmail.com
COMMENT=	Application to solve problems common to many Java applications

ONLY_FOR_ARCHS=	i386 amd64

USE_JAVA=	1.4+
USE_ANT=	yes
USE_GMAKE=	yes

DATADIR=	${PREFIX}/lib/${PORTNAME}

.include <bsd.port.pre.mk>

.if (${ARCH} == amd64)
MAKE_ARGS+=	-Dbits=64
.else
MAKE_ARGS+=	-Dbits=32
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|gcc|${CC} ${CFLAGS} -fPIC|' \
		${WRKSRC}/src/c/Makefile-freebsd-x86-32.gmake \
		${WRKSRC}/src/c/Makefile-freebsd-x86-64.gmake

do-install:
	${MKDIR} ${DATADIR}
	cd ${WRKSRC} && ${CP} -rp bin conf lib test ${DATADIR}
	${STRIP_CMD} ${DATADIR}/bin/wrapper
	${LN} -sf ${DATADIR}/bin/wrapper ${PREFIX}/bin/${PORTNAME}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${CP} -r ${WRKSRC}/doc/* ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
