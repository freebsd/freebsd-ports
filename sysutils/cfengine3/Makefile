# New ports collection makefile for:	cfengine
# Date created:		March 16, 1998
# Whom:			jseger@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	cfengine
PORTVERSION=	1.6.1
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.iu.hioslo.no/pub/cfengine/ \
		${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	cfengine

MAINTAINER=	ports@FreeBSD.org

.if defined(PACKAGE_BUILDING) && !exists(/usr/include/tcpd.h)
LIB_DEPENDS=	wrap.7:${PORTSDIR}/security/tcp_wrapper
.endif

CFLAGS+=	-pthread
USE_AUTOCONF=yes
USE_GMAKE=yes
MAKE_ENV=	INSTALL_SCRIPT="${INSTALL_SCRIPT}"

MAN8=		cfengine.8

post-install:
.for binary in cfengine cfd cfrun cfkey
	strip ${PREFIX}/sbin/${binary}
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/${PORTNAME}
.for docfile in cf-security.html cfengine-Reference.html cfengine-Tutorial.html
	${INSTALL_MAN} ${WRKSRC}/doc/${docfile} ${PREFIX}/share/doc/${PORTNAME}
.endfor
.endif

.include <bsd.port.mk>
