# Created by: <gurkan@phys.ethz.ch>
# $FreeBSD$

PORTNAME=	dphys-config
PORTVERSION=	20100216
CATEGORIES=	misc
MASTER_SITES=	DEBIAN_POOL
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool to distribute config files

RUN_DEPENDS=	wget:ftp/wget

NO_BUILD=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} -e 's|/etc|${PREFIX}/etc|' ${WRKSRC}/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/dphys-config.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/site.example/local/sbin
.for f in dphys-config.example cron.d.example init.d.example
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${EXAMPLESDIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/site.example/${PORTNAME}* \
		${STAGEDIR}${EXAMPLESDIR}/site.example/
	${INSTALL_DATA} ${WRKSRC}/site.example/local/sbin/${PORTNAME}-* \
		${STAGEDIR}${EXAMPLESDIR}/site.example/local/sbin/
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.example ${STAGEDIR}${PREFIX}/etc/${PORTNAME}.sample

.include <bsd.port.mk>
