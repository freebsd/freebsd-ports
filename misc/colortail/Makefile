# New ports collection makefile for:   colortail
# Date created:                25 February 1999
# Whom:                        Chris Piazza <cpiazza@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	colortail
PORTVERSION=	0.3.0
CATEGORIES=	misc
MASTER_SITES=	http://www.student.hk-r.se/~pt98jan/

MAINTAINER=	bugg@bugg.strangled.net

LIB_DEPENDS=	gnugetopt.1:${PORTSDIR}/devel/libgnugetopt

GNU_CONFIGURE=	yes

pre-patch:
	@${PERL} -pi.orig -e "s@malloc.h@stdlib.h@g" \
        ${WRKSRC}/CfgFileParser.cc

post-install:
	@ ${MKDIR} ${PREFIX}/share/colortail
	@ ${INSTALL_DATA} ${WRKSRC}/example-conf/conf* ${PREFIX}/share/colortail/
	@ ${ECHO} "*********************************************"
	@ ${ECHO} "Examples of the color configuration files are"
	@ ${ECHO} "in ${PREFIX}/share/colortail/"
	@ ${ECHO} "*********************************************"

.include <bsd.port.mk>
