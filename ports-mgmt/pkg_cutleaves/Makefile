# Created by: Stefan Walter <sw@gegenunendlich.de>
# $FreeBSD$

PORTNAME=	pkg_cutleaves
PORTVERSION=	20090810
CATEGORIES=	ports-mgmt
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	stefan@FreeBSD.org
COMMENT=	Interactive script for deinstalling 'leaf' packages

NO_BUILD=	yes
USES=		perl5

WRKSRC=		${WRKDIR}

MAN1=		pkg_cutleaves.1

PLIST_FILES=	sbin/pkg_cutleaves

.if defined(WITH_PKGNG)
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-pkg_cutleaves \
		${FILESDIR}/extra-patch-pkg_cutleaves.1
.endif

NO_STAGE=	yes
do-extract:
	${MKDIR} ${WRKSRC}
	${CP} ${FILESDIR}/pkg_cutleaves ${FILESDIR}/pkg_cutleaves.1 ${WRKSRC}

post-patch:
	@${REINPLACE_CMD} -e \
	  's,/usr/local/etc/pkg_leaves.exclude,${PREFIX}/etc/pkg_leaves.exclude,' \
	  ${WRKSRC}/pkg_cutleaves.1
.if defined(WITH_PKGNG)
	@${REINPLACE_CMD} \
	  -e 's,/usr/local/etc/pkg_leaves.exclude,${PREFIX}/etc/pkg_leaves.exclude,' \
	  -e 's,/usr/local/sbin/pkg delete -y,${PKG_DELETE},' \
	  -e 's,/usr/local/sbin/pkg query,${PKG_QUERY},' \
	  -e 's,/usr/bin/perl,${PERL},' \
	  ${WRKSRC}/pkg_cutleaves
.else
	@${REINPLACE_CMD} \
	  -e 's,/usr/local/etc/pkg_leaves.exclude,${PREFIX}/etc/pkg_leaves.exclude,' \
	  -e 's,/usr/sbin/pkg_delete,${PKG_DELETE},' \
	  -e 's,/usr/local/sbin/pkgdb,${LOCALBASE}/sbin/pkgdb,' \
	  -e 's,/var/db/pkg,${PKG_DBDIR},' \
	  -e 's,/usr/bin/perl,${PERL},' \
	  ${WRKSRC}/pkg_cutleaves
.endif

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pkg_cutleaves ${PREFIX}/sbin/pkg_cutleaves
	${INSTALL_MAN} ${WRKSRC}/pkg_cutleaves.1 ${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
