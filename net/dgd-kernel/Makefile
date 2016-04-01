# Created by: glewis
# $FreeBSD$

PORTNAME=	dgd-kernel
PORTVERSION=	1.3.4
PORTREVISION=	2
CATEGORIES=	net games
MASTER_SITES=	http://ftp.dworkin.nl/kernellib/ \
		http://ftp.dworkin.nl/kernellib/patches/
DISTNAME=	kernellib-${PORTVERSION}

MAINTAINER=	glewis@FreeBSD.org
COMMENT=	Kernel mudlib, for use with DGD

RUN_DEPENDS=	${LOCALBASE}/sbin/dgd:net/dgd

DIST_SUBDIR=	dgd
WRKSRC=		${WRKDIR}
NO_BUILD=	yes
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	cd ${WRKSRC} && ${FIND} . -name '*.orig' -delete

do-configure:
	${REINPLACE_CMD} -e "s:%%DATADIR%%:${DATADIR}:" \
		${WRKSRC}/kernellib/doc/kernel/kernel.dgd

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/${PORTNAME}
	@${INSTALL_DATA} ${WRKSRC}/kernellib/doc/kernel/kernel.dgd \
		${STAGEDIR}${PREFIX}/etc/${PORTNAME}/
	@${MKDIR} ${STAGEDIR}${DATADIR}/kernel
.for DIR in include kernel usr
	@cd ${WRKSRC}/kernellib && ${COPYTREE_SHARE} ${DIR} ${STAGEDIR}${DATADIR}/kernel
.endfor
	@# Install an RC script for dgd-kernel
	@${CAT} ${FILESDIR}/dgd-kernel.sh | ${SED} -e "s:%%PREFIX%%:${PREFIX}:" \
		-e "s:%%DATADIR%%:${DATADIR}:" > \
		${STAGEDIR}${PREFIX}/etc/rc.d/dgd-kernel.sh.sample
	@${CHMOD} a+x ${STAGEDIR}${PREFIX}/etc/rc.d/dgd-kernel.sh.sample
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@cd ${WRKSRC}/kernellib && ${COPYTREE_SHARE} doc ${STAGEDIR}${DOCSDIR}

post-install:
	@# Need a temporary directory for certain files
	@${MKDIR} ${STAGEDIR}${DATADIR}/tmp

.include <bsd.port.mk>
