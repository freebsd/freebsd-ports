# New ports collection makefile for: 	pipemeter
# Date created:		2003-12-02
# Whom:			Len Sassaman
#
# $FreeBSD$
#

PORTNAME=	pipemeter
PORTVERSION=	0.8.3
CATEGORIES=	sysutils
MASTER_SITES=	http://ports.abditum.com/pipemeter/ \
		http://spamaps.org/files/pipemeter/

MAINTAINER=	rabbi@abditum.com
COMMENT=	Measure speed of data going through a pipe

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

MAN1=		pipemeter.1
DOCS=		Changelog README

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pipemeter ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/pipemeter.1 ${MAN1PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
