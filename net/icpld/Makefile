# New ports collection makefile for:	icpld
# Date created:				04.01.2004
# Whom:					krion@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	icpld
PORTVERSION=	1.0.9
CATEGORIES=	net
MASTER_SITES=	http://www.ibiblio.org/icpld/download/ \
		http://voodoo.oberon.net/download/

MAINTAINER=	krion@FreeBSD.org
COMMENT=	Internet connection performance logging daemon

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

MAN1=		${PORTNAME}.1

PORTDOCS=	README
PLIST_FILES=	bin/icpld etc/icpld.conf.sample etc/rc.d/icpld.sh.sample

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/${PORTNAME}.1 ${MANPREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/icpld.conf.sample ${PREFIX}/etc
	@${ECHO_MSG} '===> Installing ${PREFIX}/etc/icpld.conf.sample file.'

	${INSTALL_SCRIPT} ${WRKSRC}/contrib/icpld.sh.sample ${PREFIX}/etc/rc.d
	@${ECHO_MSG} '===> Installing ${PREFIX}/etc/rc.d/icpld.sh.sample'

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in README
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
