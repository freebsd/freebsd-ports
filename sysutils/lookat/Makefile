# New ports collection makefile for:  lookat
# Date created:        Tue Apr 22 15:56:54 CEST 2003
# Whom:                Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$
#

PORTNAME=	lookat
PORTVERSION=	1.4.1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.wagemakers.be/uploads/37/16/
DISTNAME=	${PORTNAME}_bekijk-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A program to view Un*x text files and manual pages

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

MAN1=		lookat.1

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e \
	's|/etc/lookat.conf|${PREFIX}/etc/lookat.conf|g' ${WRKSRC}/${PORTNAME}.1

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/lookat ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/lookat.1 ${PREFIX}/man/man1
	@${INSTALL_DATA} ${WRKSRC}/lookat.conf.default ${PREFIX}/etc
	@${ECHO} "------------------------------------------------------------"
	@${ECHO} "Sample of configuration file placed at"
	@${ECHO} "${PREFIX}/etc/lookat.conf.default"
	@${ECHO} "------------------------------------------------------------"
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
