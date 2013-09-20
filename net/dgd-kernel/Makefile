# Created by: glewis
# $FreeBSD$

PORTNAME=	dgd-kernel
PORTVERSION=	1.3.4
PORTREVISION=	1
CATEGORIES=	net games
MASTER_SITES=	http://ftp.dworkin.nl/kernellib/ \
		http://ftp.dworkin.nl/kernellib/patches/
DISTNAME=	kernellib-${PORTVERSION}

MAINTAINER=	glewis@FreeBSD.org
COMMENT=	Kernel mudlib, for use with DGD

RUN_DEPENDS=	${LOCALBASE}/sbin/dgd:${PORTSDIR}/net/dgd

DIST_SUBDIR=	dgd
WRKSRC=		${WRKDIR}
NO_BUILD=	yes
.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

NO_STAGE=	yes
post-patch:
	cd ${WRKSRC} && ${FIND} . -name '*.orig' -delete

do-configure:
	${REINPLACE_CMD} -e "s:%%DATADIR%%:${DATADIR}:" \
		${WRKSRC}/kernellib/doc/kernel/kernel.dgd

do-install:
	@${MKDIR} ${PREFIX}/etc/${PORTNAME}
	@${INSTALL_DATA} ${WRKSRC}/kernellib/doc/kernel/kernel.dgd \
		${PREFIX}/etc/${PORTNAME}/
	@${MKDIR} ${DATADIR}/kernel
.for DIR in include kernel usr
	@cd ${WRKSRC}/kernellib && ${COPYTREE_SHARE} ${DIR} ${DATADIR}/kernel
.endfor
	@# Install an RC script for dgd-kernel
	@${CAT} ${FILESDIR}/dgd-kernel.sh | ${SED} -e "s:%%PREFIX%%:${PREFIX}:" \
		-e "s:%%DATADIR%%:${DATADIR}:" > \
		${PREFIX}/etc/rc.d/dgd-kernel.sh.sample
	@${CHMOD} a+x ${PREFIX}/etc/rc.d/dgd-kernel.sh.sample
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC}/kernellib && ${COPYTREE_SHARE} doc ${DOCSDIR}
.endif

post-install:
	@# Need a temporary directory for certain files
	@${MKDIR} ${DATADIR}/tmp
	@# Set mudlib ownership
	-@${CHOWN} -h -R mud:mud ${DATADIR}

.include <bsd.port.mk>
