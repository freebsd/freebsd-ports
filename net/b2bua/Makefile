# New ports collection makefile for:	b2bua
# Date created:				6 December 2002
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	b2bua
PORTVERSION=	1.5.0
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://www.vovida.org/downloads/sip/${PORTVERSION}/
DISTNAME=	sip-${PORTVERSION}

MAINTAINER=	sobomax@FreeBSD.org
COMMENT=	A back-to-back (B2B) SIP user agent

LIB_DEPENDS=	xml2.5:${PORTSDIR}/textproc/libxml2

USE_GMAKE=	yes
ALL_TARGET=	b2bua
CFLAGS+=	-Wno-deprecated
MAKE_ENV=	PTHREAD_LDFLAGS="${PTHREAD_LIBS}" \
		PTHREAD_LIBNAME="${PTHREAD_LIBNAME}" \
		VOCAL_USE_SYSTEM_LIBXML=true

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sip/b2b/bin.nodebug.FreeBSD.${MACHINE_ARCH}/b2bua \
		${PREFIX}/bin
	${MKDIR} ${DOCSDIR}
.for file in LICENSE HOWTO HOWTO.PROV b2bdesign.pdf
	${INSTALL_DATA} ${WRKSRC}/sip/b2b/${file} ${DOCSDIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/sip/b2b/b2bConfig.xml \
		${PREFIX}/etc/b2bConfig.xml.sample

.include <bsd.port.mk>
