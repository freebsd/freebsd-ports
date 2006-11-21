# New ports collection makefile for:	dphys-config
# Date created:				12 Oct 2006
# Whom:					<gurkan@linuks.mine.nu>
#
# $FreeBSD$
#

PORTNAME=	dphys-config
PORTVERSION=	20061013
CATEGORIES=	misc
MASTER_SITES=	http://www.phys.ethz.ch/~franklin/Projects/ \
		http://florida.ethz.ch/ports/distfiles/ \

MAINTAINER=	gurkan@linuks.mine.nu
COMMENT=	Tool to distribute config files

RUN_DEPENDS=	wget:${PORTSDIR}/ftp/wget

NO_BUILD=	yes

MAN1=		dphys-config.1

BROKEN=		not fetchable

post-patch:
	@${REINPLACE_CMD} -e 's|/etc|${PREFIX}/etc|' ${WRKSRC}/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${MAN1PREFIX}/man/man1
	${MKDIR} ${EXAMPLESDIR}/site.example/local/sbin
.for f in dphys-config.example cron.d.example init.d.example
	${INSTALL_DATA} ${WRKSRC}/${f} ${EXAMPLESDIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/site.example/${PORTNAME}* \
		${EXAMPLESDIR}/site.example/
	${INSTALL_DATA} ${WRKSRC}/site.example/local/sbin/${PORTNAME}-* \
		${EXAMPLESDIR}/site.example/local/sbin/
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.example ${PREFIX}/etc/${PORTNAME}.sample
.if !exists(${PREFIX}/etc/${PORTNAME})
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.example ${PREFIX}/etc/${PORTNAME}
.endif

.include <bsd.port.mk>
