# New ports collection makefile for:	b2bua
# Date created:				6 December 2002
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	b2bua
PORTVERSION=	1.4.0
CATEGORIES=	net
MASTER_SITES=	http://www.vovida.org/downloads/b2bua/

MAINTAINER=	sobomax@FreeBSD.org

LIB_DEPENDS=	xml2.5:${PORTSDIR}/textproc/libxml2 \
		lthread:${PORTSDIR}/devel/linuxthreads

USE_GMAKE=	yes
ALL_TARGET=	b2bua
CFLAGS+=	-I${LOCALBASE}/include/pthread/linuxthreads \
		-I${LOCALBASE}/include/libxml2 \
		-I${LOCALBASE}/include/libxml2/libxml \
		-I${LOCALBASE}/include -Wno-deprecated
PTHREAD_LDFLAGS=	-L${LOCALBASE}/lib -llthread -llgcc_r
MAKE_ENV=	PTHREAD_LDFLAGS="${PTHREAD_LDFLAGS}" \
		PTHREAD_LIBNAME=""

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500035
PTHREAD_LDFLAGS+=	-llstdc++ -llsupc++
.endif

.if !exists(/usr/include/getopt.h)
LIB_DEPENDS+=	gnugetopt.1:${PORTSDIR}/devel/libgnugetopt
PTHREAD_LDFLAGS+=	-lgnugetopt
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sip/b2b/bin.nodebug.FreeBSD.i386/b2bua \
		${PREFIX}/bin
	${MKDIR} ${DOCSDIR}
.for file in README HOWTO b2bdesign.pdf Doc/B2BUA.pdf
	${INSTALL_DATA} ${WRKSRC}/sip/b2b/${file} ${DOCSDIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/sip/b2b/b2bConfig.xml \
		${PREFIX}/etc/b2bConfig.xml.sample

.include <bsd.port.post.mk>
