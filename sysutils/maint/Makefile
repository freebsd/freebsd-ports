# New ports collection makefile for:	maint
# Date created:				02-May-2001
# Whom:					Dale Weber <netman@dynaplex.net>
#
# $FreeBSD$
#

PORTNAME=	maint
PORTVERSION=	0.5.2
CATEGORIES=	sysutils python
MASTER_SITES=	http://www.dynaplex.net/opensource/software/

MAINTAINER=	ports@FreeBSD.Org

BUILD_DEPENDS=	cvsup:${PORTSDIR}/net/cvsup
RUN_DEPENDS=	cvsup:${PORTSDIR}/net/cvsup

USE_PYTHON=	yes
NO_BUILD=	yes

BINDIR=		${PREFIX}/bin
MYCONFDIR=	${PREFIX}/etc/maint
MYSCRIPTDIR=	${MYCONFDIR}/scripts
MYSUPFILESDIR=	${MYCONFDIR}/supfiles
MYSHAREDIR=	${PREFIX}/share/maint
MYDATADIR=	${MYSHAREDIR}/data
MYLOGSDIR=	${MYSHAREDIR}/logs
MYDOCDIR=	${MYSHAREDIR}/doc

do-install:
	${MKDIR} ${MYCONFDIR}
	${MKDIR} ${MYSCRIPTDIR}
	${MKDIR} ${MYSUPFILESDIR}
	${MKDIR} ${MYSHAREDIR}
	${MKDIR} ${MYDOCDIR}
	${MKDIR} ${MYDATADIR}
	${MKDIR} ${MYLOGSDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/maint* ${BINDIR}
	${INSTALL_DATA} ${WRKSRC}/share/maint/data/* ${MYDATADIR}
	${INSTALL_DATA} ${WRKSRC}/etc/maint/*.sample ${MYCONFDIR}
	${INSTALL_DATA} ${WRKSRC}/etc/maint/scripts/* ${MYSCRIPTDIR}
	${INSTALL_DATA} ${WRKSRC}/etc/maint/supfiles/* ${MYSUPFILESDIR}
	${INSTALL_DATA} ${WRKSRC}/share/maint/logs/* ${MYLOGSDIR}
	${INSTALL_MAN} ${WRKSRC}/share/maint/doc/* ${MYDOCDIR}
	${INSTALL_SCRIPT} ${BINDIR}/maint.py ${BINDIR}/maint

.include <bsd.port.mk>
