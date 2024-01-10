PORTNAME=	pkg_cutleaves
PORTVERSION=	20181216
PORTREVISION=	1
CATEGORIES=	ports-mgmt
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Interactive script for deinstalling 'leaf' packages

LICENSE=	BSD2CLAUSE

USES=		perl5 shebangfix

NO_BUILD=	yes
SHEBANG_FILES=	pkg_cutleaves
NO_WRKSUBDIR=	yes

PLIST_FILES=	sbin/pkg_cutleaves share/man/man1/pkg_cutleaves.1.gz
NO_ARCH=	yes

do-extract:
	${MKDIR} ${WRKSRC}
	${CP} ${FILESDIR}/pkg_cutleaves ${FILESDIR}/pkg_cutleaves.1 ${WRKSRC}

post-patch:
	@${REINPLACE_CMD} -e \
	  's,/usr/local/etc/pkg_leaves.exclude,${PREFIX}/etc/pkg_leaves.exclude,' \
	  ${WRKSRC}/pkg_cutleaves.1
	@${REINPLACE_CMD} \
	  -e 's,/usr/local/etc/pkg_leaves.exclude,${PREFIX}/etc/pkg_leaves.exclude,' \
	  -e 's,/usr/local/sbin/pkg delete -y,${PKG_DELETE},' \
	  -e 's,/usr/local/sbin/pkg query,${PKG_QUERY},' \
	  ${WRKSRC}/pkg_cutleaves

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pkg_cutleaves ${STAGEDIR}${PREFIX}/sbin/pkg_cutleaves
	${INSTALL_MAN} ${WRKSRC}/pkg_cutleaves.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
