# New ports collection makefile for:	dgd
# Date created:		23 August 1994
# Whom:			adam@veda.is
#
# $FreeBSD$
#

PORTNAME=	dgd
PORTVERSION=	1.2p3
PORTREVISION=	1
CATEGORIES=	net lang games
MASTER_SITES=	${MASTER_SITE_LOCAL:S|%SUBDIR%|glewis/dgd|} \
		ftp://ftp.dworkin.nl/pub/dgd/ \
		ftp://ftp.imaginary.com/pub/LPC/servers/DGD/

MAINTAINER=	glewis@FreeBSD.org
COMMENT=	Dworkin's Generic Driver (network server)

NO_CDROM=	"no distribution to corporate environment"
RESTRICTED=	"license required for commercial use"

DIST_SUBDIR=	dgd
WRKSRC=		${WRKDIR}/dgd/src
ALL_TARGET=	install
USE_REINPLACE=	yes

CPIO?=          /usr/bin/cpio

do-configure:
	${REINPLACE_CMD} -e "s:%%DATADIR%%:${DATADIR}:" ${WRKDIR}/dgd/mud.dgd

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
	${INSTALL_DATA} ${WRKDIR}/dgd/Copyright ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/dgd/Credits ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/dgd/README ${DOCSDIR}
	cd ${WRKDIR}/dgd/doc && ${FIND} . \
		| ${CPIO} -pdmu -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}
.endif

post-install:
	# Need a temporary directory for certain files
	${MKDIR} ${DATADIR}/tmp
	# Run package install script
	${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGDIR}/pkg-install ${PKGNAME} \
		POST-INSTALL

.include <bsd.port.mk>
