# ex:ts=8
# New ports collection makefile for:	opencl
# Date created:			Mar 3, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	opencl
PORTVERSION=	0.8.2
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	OpenCL-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org

USE_NEWGCC=	yes
HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	configure.pl
CONFIGURE_ARGS=	gcc-freebsd-generic
USE_GMAKE=	yes
MAKE_ARGS=	LANG_FLAGS="-fpermissive -ansi"
INSTALLS_SHLIB=	yes

PLIST_SUB=	PORTVERSION=${PORTVERSION}

post-patch:
	@${PERL} -pi -e "s,%%PREFIX%%,${PREFIX},g ; \
		s,%%CFLAGS%%,${CFLAGS},g" ${WRKSRC}/${CONFIGURE_SCRIPT}
	@${RM} -f ${WRKSRC}/src/pipe_io.cpp.orig

.include <bsd.port.mk>
