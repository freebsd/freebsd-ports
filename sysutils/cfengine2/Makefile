# New ports collection makefile for:	cfengine
# Date created:		March 16, 1998
# Whom:			jseger@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	cfengine
PORTVERSION=	1.6.3
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.iu.hioslo.no/pub/cfengine/ \
		${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	gordont@gnf.org

LIB_DEPENDS=	db3:${PORTSDIR}/databases/db3
.if defined(PACKAGE_BUILDING) && !exists(/usr/include/tcpd.h)
LIB_DEPENDS+=	wrap.7:${PORTSDIR}/security/tcp_wrapper
.endif

USE_GMAKE=	yes
USE_AUTOMAKE_VER=14

MAN8=		cfengine.8

pre-configure:
	@cd ${WRKSRC} && ${ACLOCAL} && ${AUTOHEADER}

post-install:
.if defined(NOPORTDOCS)
	@${RM} -rf ${PREFIX}/share/doc/${PORTNAME}
.endif
.for binary in cfd cfengine cfrun cfkey
	@strip ${PREFIX}/sbin/${binary}
.endfor

.include <bsd.port.mk>
