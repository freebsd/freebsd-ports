# ex:ts=8
# New ports collection makefile for:	botan
# Date created:			Mar 3, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	botan
PORTVERSION=	1.0.1
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	opencl
DISTNAME=	Botan-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org

USE_REINPLACE=	yes
USE_PERL5=	yes
HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	configure.pl
CONFIGURE_ARGS=	gcc-freebsd-generic
USE_GMAKE=	yes
MAKE_ARGS=	LANG_FLAGS="-fpermissive -ansi"
INSTALLS_SHLIB=	yes

PLIST_SUB=	PORTVERSION=${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} -e "s,%%PREFIX%%,${PREFIX},g ; \
		s,%%CFLAGS%%,${CFLAGS},g" ${WRKSRC}/${CONFIGURE_SCRIPT}
	@${RM} -f ${WRKSRC}/src/pipe_io.cpp.orig

post-install:
	@${RM} -f ${PREFIX}/include/botan/botan

.include <bsd.port.mk>
