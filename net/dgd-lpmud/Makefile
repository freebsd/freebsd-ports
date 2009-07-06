# New ports collection makefile for:	dgd-lpmud
# Date created:		10 November 1994
# Whom:			adam
#
# $FreeBSD$
#

PORTNAME=	dgd-lpmud
PORTVERSION=	2.4.5
PORTREVISION=	1
CATEGORIES=	net games
MASTER_SITES=	ftp://ftp.lysator.liu.se/pub/lpmud/drivers/dgd/lpc/ \
		${MASTER_SITE_LOCAL:S|%SUBDIR%|glewis/dgd|}
DISTNAME=	2.4.5-for-1.1
EXTRACT_SUFX=	.tgz

MAINTAINER=	glewis@FreeBSD.org
COMMENT=	LPmud mudlib, for use with DGD

RUN_DEPENDS=	${LOCALBASE}/sbin/dgd:${PORTSDIR}/net/dgd

RESTRICTED=	no monetary gain, tarball OK for CDROM

DIST_SUBDIR=	dgd
WRKSRC=		${WRKDIR}/mud

post-extract:
	@${CP} ${FILESDIR}/oconv.c ${WRKSRC}/
	@${CP} ${FILESDIR}/Makefile.bin ${WRKSRC}/Makefile

post-patch:
	cd ${WRKSRC} && ${FIND} . -name '*.orig' -delete

do-configure:
	${REINPLACE_CMD} -e "s:%%DATADIR%%:${DATADIR}:" ${WRKSRC}/lpmud.dgd

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hname ${PREFIX}/bin/lpmud-hname
	${INSTALL_PROGRAM} ${WRKSRC}/oconv ${PREFIX}/bin/lpmud-oconv
	${MKDIR} ${PREFIX}/etc/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/lpmud.dgd ${PREFIX}/etc/${PORTNAME}/
	${MKDIR} ${DATADIR}/lpmud
	cd ${WRKSRC}/2.4.5 && ${FIND} . \
		| ${CPIO} -pdmu -R ${SHAREOWN}:${SHAREGRP} ${DATADIR}/lpmud
	# Install an RC script for dgd-lpmud
	${CAT} ${FILESDIR}/dgd-lpmud.sh | ${SED} -e "s:%%PREFIX%%:${PREFIX}:" \
		-e "s:%%DATADIR%%:${DATADIR}:" > \
		${PREFIX}/etc/rc.d/dgd-lpmud.sh.sample
	${CHMOD} a+x ${PREFIX}/etc/rc.d/dgd-lpmud.sh.sample
	${MV} ${DATADIR}/lpmud/ACCESS.ALLOW \
		${DATADIR}/lpmud/ACCESS.ALLOW.example
	${MV} ${DATADIR}/lpmud/ACCESS.DENY \
		${DATADIR}/lpmud/ACCESS.DENY.example
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

post-install:
	# Need a temporary directory for certain files
	${MKDIR} ${DATADIR}/tmp
	# Link in the dgd docs
	${LN} -sf ${PREFIX}/share/doc/dgd/kfun ${DATADIR}/lpmud/doc
	# Run package install script
	${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGDIR}/pkg-install ${PKGNAME} \
		POST-INSTALL
	# Set mudlib ownership
	-@${CHOWN} -h -R mud:mud ${DATADIR}

.include <bsd.port.mk>
