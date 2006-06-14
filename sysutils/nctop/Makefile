# ports collection Makefile for: nctop
# Date created:		01 August 2005
# Whom:			Ralf Becker <nctop@web.de>
#
# $FreeBSD$
#

PORTNAME=	nctop
PORTVERSION=	0.23.1
CATEGORIES=	sysutils
MASTER_SITES=   http://www.rz.uni-karlsruhe.de/~hj28/download.php?file=/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A remote system monitor

USE_AUTOTOOLS=	autoconf:259:env
USE_BZIP2=	YES

HAS_CONFIGURE=	yes
CONFIGURE_ARGS= --prefix=${PREFIX} \
		--with-libwrap     \
		--with-setgid=kmem

MAN1=		nctopd.1 nctop.1

pre-configure:
	${CP} ${AUTOCONF_DIR}/install-sh ${WRKSRC}
	${CP} ${AUTOCONF_DIR}/config.sub ${WRKSRC}
	${CP} ${AUTOCONF_DIR}/config.guess ${WRKSRC}
	cd ${WRKSRC} && ${AUTOCONF}

.include <bsd.port.mk>
