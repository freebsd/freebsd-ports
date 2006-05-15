# New ports collection makefile for:	whoson
# Date created:				14 May 2006
# Whom:					Sergey Matveychuk <sem@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	whoson
PORTVERSION=	2.03
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	sem@FreeBSD.org
COMMENT=	`WHO iS ONline' protocol implementation

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=		--with-config=${PREFIX}/etc/whoson.conf
INSTALLS_SHLIB=	yes

USE_RC_SUBR=	whoson.sh

MAN3=	whoson.3 wso_login.3 wso_logout.3 wso_query.3 wso_version.3
MAN5=	whoson.conf.5
MAN8=	whoson.8 whosond.8

PORTDOCS=	README ChangeLog

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
