# Created by: Dmitry Semkin <lslarry@gmail.com>
# $FreeBSD$

PORTNAME=	srg
PORTVERSION=	1.3.6
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION} \
		http://mirror.crc.net.nz/pub/srg/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Squid Report Generator

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USE_BZIP2=	yes
GNU_CONFIGURE=	yes

MAN1=		srg.1

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e \
		'/CPPFLAGS/s|-I/usr/local/include|| ; \
		 /LDFLAGS/s|-L/usr/local/lib||' ${WRKSRC}/configure

post-install:
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
.for ex in srg.daily srg.monthly srg.weekly
	${INSTALL_DATA} ${WRKSRC}/examples/${ex} ${EXAMPLESDIR}
.endfor
.endif

.include <bsd.port.mk>
