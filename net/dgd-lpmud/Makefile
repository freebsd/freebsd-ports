# Created by: adam
# $FreeBSD$

PORTNAME=	dgd-lpmud
PORTVERSION=	2.4.5
PORTREVISION=	6
CATEGORIES=	net games
MASTER_SITES=	LOCAL/glewis/dgd \
		http://ftp.dworkin.nl/dgd/lib/
DISTNAME=	2.4.5-for-1.4

MAINTAINER=	glewis@FreeBSD.org
COMMENT=	LPmud mudlib, for use with DGD

LICENSE=	LPMUD
LICENSE_NAME=	LPmud license
LICENSE_FILE=	${WRKSRC}/${PORTVERSION}/Copyright
LICENSE_PERMS=	dist-mirror no-dist-sell pkg-mirror no-pkg-sell auto-accept

RUN_DEPENDS=	${LOCALBASE}/sbin/dgd:net/dgd

USES=		tar:tgz

DIST_SUBDIR=	dgd
WRKSRC=		${WRKDIR}/mud

OPTIONS_DEFINE=	DOCS

post-extract:
	@${CP} ${FILESDIR}/oconv.c ${WRKSRC}/
	@${CP} ${FILESDIR}/Makefile.bin ${WRKSRC}/Makefile

post-patch:
	(cd ${WRKSRC} && ${FIND} . -name '*.orig' -delete)

do-configure:
	${REINPLACE_CMD} -e "s:%%DATADIR%%:${DATADIR}:" ${WRKSRC}/lpmud.dgd

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hname ${STAGEDIR}${PREFIX}/bin/lpmud-hname
	${INSTALL_PROGRAM} ${WRKSRC}/oconv ${STAGEDIR}${PREFIX}/bin/lpmud-oconv
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/lpmud.dgd ${STAGEDIR}${PREFIX}/etc/${PORTNAME}/
	${MKDIR} ${STAGEDIR}${DATADIR}/lpmud
	(cd ${WRKSRC}/2.4.5 && ${FIND} . \
		| ${CPIO} -pdmu -R ${SHAREOWN}:${SHAREGRP} ${STAGEDIR}${DATADIR}/lpmud)
	# Install an RC script for dgd-lpmud
	${CAT} ${FILESDIR}/dgd-lpmud.sh | ${SED} -e "s:%%PREFIX%%:${PREFIX}:" \
		-e "s:%%DATADIR%%:${DATADIR}:" > \
		${STAGEDIR}${PREFIX}/etc/rc.d/dgd-lpmud.sh.sample
	${CHMOD} a+x ${STAGEDIR}${PREFIX}/etc/rc.d/dgd-lpmud.sh.sample
	${MV} ${STAGEDIR}${DATADIR}/lpmud/ACCESS.ALLOW \
		${STAGEDIR}${DATADIR}/lpmud/ACCESS.ALLOW.example
	${MV} ${STAGEDIR}${DATADIR}/lpmud/ACCESS.DENY \
		${STAGEDIR}${DATADIR}/lpmud/ACCESS.DENY.example
	# Need a temporary directory for certain files
	${MKDIR} ${STAGEDIR}${DATADIR}/tmp
	# Link in the dgd docs
	${LN} -sf ${PREFIX}/share/doc/dgd/kfun ${STAGEDIR}${DATADIR}/lpmud/doc

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
