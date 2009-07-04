# New ports collection makefile for:	dgd
# Date created:		23 August 1994
# Whom:			adam@veda.is
#
# $FreeBSD$
#

PORTNAME=	dgd
PORTVERSION=	1.3
CATEGORIES=	net lang games
MASTER_SITES=	${MASTER_SITE_LOCAL:S|%SUBDIR%|glewis/dgd|} \
		http://ftp.dworkin.nl/dgd/

MAINTAINER=	glewis@FreeBSD.org
COMMENT=	Dworkin's Generic Driver (network server)

NO_CDROM=	no distribution to corporate environment
RESTRICTED=	license required for commercial use

OPTIONS=	NETWORKING	"With networking kfuns"		off

DIST_SUBDIR=	dgd
WRKSRC=		${WRKDIR}/dgd/src
PATCH_WRKSRC=	${WRKDIR}/dgd
ALL_TARGET=	install

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

.include <bsd.port.pre.mk>

.if defined(WITH_NETWORKING)
PATCH_SITES+=	http://ftp.dworkin.nl/dgd/pkg/
PATCHFILES+=	Network-6-DGD-1.3.patch.gz
PLIST_SUB+=	NETWORKING=""
PATCH_DIST_STRIP=	-p1
PATCH_STRIP=		-p0 -F 3
.else
PLIST_SUB+=	NETWORKING="@comment "
.endif

post-patch:
	@${MV} ${WRKSRC}/host/Makefile.bsd ${WRKSRC}/host/Makefile
	@# There are here since the networking package modifies either these
	@# lines or lines near them so they cannot be applied as patches.
	@${REINPLACE_CMD} -e "s:^directory\([[:space:]]\)=\([[:space:]]\)\"[^\"]*\":directory\1=\2\"${DATADIR}/kernel\":" ${WRKDIR}/dgd/mud.dgd
	@${REINPLACE_CMD} -e "/^DEBUG/d" ${WRKSRC}/Makefile

.ifdef (WITH_NETWORKING)
post-configure:
	cd ${WRKDIR}/dgd/ && ${FIND} . -name '*.orig' -delete
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/dgd/bin/driver ${PREFIX}/sbin/dgd
	${INSTALL_PROGRAM} ${WRKDIR}/dgd/bin/precomp ${PREFIX}/bin/precomp
	${MKDIR} ${PREFIX}/etc/${PORTNAME}
	${INSTALL_DATA} ${WRKDIR}/dgd/mud.dgd \
		${PREFIX}/etc/${PORTNAME}/kernel.dgd
	${MKDIR} ${DATADIR}/kernel
	cd ${WRKDIR}/dgd/mud && ${FIND} . \
		| ${CPIO} -pdmu -R ${SHAREOWN}:${SHAREGRP} ${DATADIR}/kernel
	# Install an RC script for DGD
	${CAT} ${FILESDIR}/dgd.sh | ${SED} -e "s:%%PREFIX%%:${PREFIX}:" \
		-e "s:%%DATADIR%%:${DATADIR}:" > \
		${PREFIX}/etc/rc.d/dgd.sh.sample
	${CHMOD} a+x ${PREFIX}/etc/rc.d/dgd.sh.sample
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.ifdef (WITH_NETWORKING)
	${INSTALL_DATA} ${WRKDIR}/dgd/Changelog.NET ${DOCSDIR}
.endif
	${INSTALL_DATA} ${WRKDIR}/dgd/Copyright ${DOCSDIR}
.ifdef (WITH_NETWORKING)
	${INSTALL_DATA} ${WRKDIR}/dgd/Copyright.NET ${DOCSDIR}
.endif
	${INSTALL_DATA} ${WRKDIR}/dgd/Credits ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/dgd/README ${DOCSDIR}
.ifdef (WITH_NETWORKING)
	${INSTALL_DATA} ${WRKDIR}/dgd/README.NET ${DOCSDIR}
.endif
	cd ${WRKDIR}/dgd/doc && ${FIND} . \
		| ${CPIO} -pdmu -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}
.endif

post-install:
	# Need a temporary directory for certain files
	${MKDIR} ${DATADIR}/tmp
	# Run package installation script
	${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGDIR}/pkg-install ${PKGNAME} \
		POST-INSTALL
	# Set mudlib ownership
	-@${CHOWN} -h -R mud:mud ${DATADIR}

.include <bsd.port.post.mk>
