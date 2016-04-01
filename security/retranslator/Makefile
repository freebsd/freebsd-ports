# Created by: Gvozdikov Veniamin <g.veniamin@googlemail.com>
# $FreeBSD$

PORTNAME=	retranslator
PORTVERSION=	5.0.0
DISTVERSIONSUFFIX=	-7
CATEGORIES=	security
MASTER_SITES=	http://utils.kaspersky.com/updater/retranslator_5.0.0.7/FreeBSD_6.3/ \
		LOCAL/vg

MAINTAINER=	vg@FreeBSD.org
COMMENT=	The update utility for Kaspersky applications

NO_BUILD=	yes
ONLY_FOR_ARCHS=	i386 amd64

WRKSRC=		${WRKDIR}/${PORTNAME}

LIB_DEPENDS+=	libm.so:misc/compat6x

do-configure:

.for f in 's,./backup/,/var/db/${PORTNAME}/backup,g' \
	's,./bases/,/var/db/${PORTNAME}/bases,g' \
	's,./${PORTNAME}.log,/var/log/${PORTNAME}.log,g'
	@${REINPLACE_CMD} -e ${f} \
		${WRKSRC}/${PORTNAME}.conf
.endfor

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME}.bin \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}

post-install:
	@${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.conf \
		${STAGEDIR}${PREFIX}/etc/${PORTNAME}.conf.sample

.include <bsd.port.mk>
