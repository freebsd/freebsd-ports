# New ports collection makefile for:	pkg_cutleaves
# Date created:		27 July 2003
# Whom:			Stefan Walter <sw@gegenunendlich.de>
#
# $FreeBSD$
#

PORTNAME=	pkg_cutleaves
PORTVERSION=	20040517
CATEGORIES=	sysutils
MASTER_SITES=	http://www.gegenunendlich.de/projects/${PORTNAME}/

MAINTAINER=	sw@gegenunendlich.de
COMMENT=	Interactive script for deinstalling 'leaf' packages

RUN_DEPENDS=	${LOCALBASE}/sbin/pkg_deinstall:${PORTSDIR}/sysutils/portupgrade

NO_BUILD=	yes
USE_PERL5=	yes
USE_REINPLACE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

MAN1=		pkg_cutleaves.1

PLIST_FILES=	sbin/pkg_cutleaves

post-patch:
	@${REINPLACE_CMD} -e \
	  's,/usr/local/etc/pkg_leaves.exclude,${PREFIX}/etc/pkg_leaves.exclude,' \
	  ${WRKSRC}/pkg_cutleaves.1
	@${REINPLACE_CMD} -e \
	  's,/usr/local/etc/pkg_leaves.exclude,${PREFIX}/etc/pkg_leaves.exclude,' \
	  ${WRKSRC}/pkg_cutleaves
	@${REINPLACE_CMD} -e \
	  's,/usr/local/sbin/pkg_deinstall,${LOCALBASE}/sbin/pkg_deinstall,' \
	  ${WRKSRC}/pkg_cutleaves
	@${REINPLACE_CMD} -e \
	  's,/usr/local/sbin/pkgdb,${LOCALBASE}/sbin/pkgdb,' \
	  ${WRKSRC}/pkg_cutleaves
	@${REINPLACE_CMD} -e \
	  's,/var/db/pkg,${PKG_DBDIR},' \
	  ${WRKSRC}/pkg_cutleaves
	@${REINPLACE_CMD} -e 's,/usr/bin/perl,${PERL},' \
	  ${WRKSRC}/pkg_cutleaves

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pkg_cutleaves ${PREFIX}/sbin/pkg_cutleaves
	${INSTALL_MAN} ${WRKSRC}/pkg_cutleaves.1 ${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
