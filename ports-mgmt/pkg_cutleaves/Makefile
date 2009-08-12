# New ports collection makefile for:	pkg_cutleaves
# Date created:		27 July 2003
# Whom:			Stefan Walter <sw@gegenunendlich.de>
#
# $FreeBSD$
#

PORTNAME=	pkg_cutleaves
PORTVERSION=	20090810
CATEGORIES=	ports-mgmt
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	stefan@FreeBSD.org
COMMENT=	Interactive script for deinstalling 'leaf' packages

NO_BUILD=	yes
USE_PERL5=	yes

WRKSRC=		${WRKDIR}

MAN1=		pkg_cutleaves.1

PLIST_FILES=	sbin/pkg_cutleaves

do-extract:
	${MKDIR} ${WRKSRC}
	${CP} ${FILESDIR}/pkg_cutleaves ${FILESDIR}/pkg_cutleaves.1 ${WRKSRC}

post-patch:
	@${REINPLACE_CMD} -e \
	  's,/usr/local/etc/pkg_leaves.exclude,${PREFIX}/etc/pkg_leaves.exclude,' \
	  ${WRKSRC}/pkg_cutleaves.1
	@${REINPLACE_CMD} \
	  -e 's,/usr/local/etc/pkg_leaves.exclude,${PREFIX}/etc/pkg_leaves.exclude,' \
	  -e 's,/usr/sbin/pkg_delete,${PKG_DELETE},' \
	  -e 's,/usr/local/sbin/pkgdb,${LOCALBASE}/sbin/pkgdb,' \
	  -e 's,/var/db/pkg,${PKG_DBDIR},' \
	  -e 's,/usr/bin/perl,${PERL},' \
	  ${WRKSRC}/pkg_cutleaves

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pkg_cutleaves ${PREFIX}/sbin/pkg_cutleaves
	${INSTALL_MAN} ${WRKSRC}/pkg_cutleaves.1 ${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
