# New ports collection makefile for:  lookat
# Date created:        Tue Apr 22 15:56:54 CEST 2003
# Whom:                Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$
#

PORTNAME=	lookat
PORTVERSION=	1.4.0
CATEGORIES=	sysutils
MASTER_SITES=	http://www.wagemakers.be/uploads/37/7/
DISTNAME=	${PORTNAME}_bekijk-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Lookat is a program to view Un*x text files and manual pages

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_GMAKE=	yes
USE_REINPLACE=	yes

MAN1=		lookat.1

post-patch:
	@${REINPLACE_CMD} -e \
	's|/etc/lookat.conf|${PREFIX}/etc/lookat.conf|g' ${WRKSRC}/${PORTNAME}.1

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/lookat ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/lookat.1 ${PREFIX}/man/man1
	@${INSTALL_DATA} ${WRKSRC}/lookat.conf ${PREFIX}/etc/lookat.conf.sample
	@${ECHO} "------------------------------------------------------------"
	@${ECHO} "Sample of configuration file placed at"
	@${ECHO} "${PREFIX}/etc/lookat.conf.sample"
	@${ECHO} "------------------------------------------------------------
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
