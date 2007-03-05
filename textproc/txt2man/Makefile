# ex:ts=8
# New ports collection makefile for:	txt2man
# Date created:			Jun 14, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	txt2man
PORTVERSION=	1.5.2
CATEGORIES=	textproc
MASTER_SITES=	http://mvertes.free.fr/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Converts flat ASCII text to man page format

BUILD_DEPENDS=	gawk:${PORTSDIR}/lang/gawk
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_GMAKE=	yes
INSTALL_TARGET=	install prefix=${PREFIX}

MAN1=		bookman.1 src2man.1 txt2man.1
PLIST_FILES=	bin/bookman bin/src2man bin/txt2man

post-patch:
	@${REINPLACE_CMD} -e "s,awk,gawk," ${WRKSRC}/bookman ${WRKSRC}/src2man

.include <bsd.port.mk>
