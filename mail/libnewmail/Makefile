# New ports collection makefile for:  		libnewmail
# Date created:        				05.06.2003
# Whom:               				Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$
#

PORTNAME=	libnewmail
PORTVERSION=	0.3
PORTREVISION=	12
CATEGORIES=	mail
MASTER_SITES=	http://0pointer.de/lennart/projects/libnewmail/ \
		http://www.stud.uni-hamburg.de/~lennart/projects/libnewmail/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Generic mail checking library

LIB_DEPENDS=	gnutls.13:${PORTSDIR}/security/gnutls \
		oop.4:${PORTSDIR}/devel/liboop

USE_AUTOTOOLS=	libltdl:15 libtool:15
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS+=	--disable-doxygen --disable-lynx

DOC_FILES=	README \
		README.html \
		doxygen.conf

post-patch:
	@${REINPLACE_CMD} -e \
	's|#include <wait.h>|#include <sys/wait.h>|g' \
		${WRKSRC}/src/imap.c

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for doc in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/doc/${doc} ${DOCSDIR}
.endfor
	@${CP} -R ${WRKSRC}/doc/reference/html/ ${DOCSDIR}
.endif

.include <bsd.port.mk>
