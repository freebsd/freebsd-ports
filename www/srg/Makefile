# Created by: Dmitry Semkin <lslarry@gmail.com>
# $FreeBSD$

PORTNAME=	srg
PORTVERSION=	1.3.6
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION} \
		http://mirror.crc.net.nz/pub/srg/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Squid Report Generator

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		tar:bzip2
GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	EXAMPLES

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e \
		'/CPPFLAGS/s|-I/usr/local/include|| ; \
		 /LDFLAGS/s|-L/usr/local/lib||' ${WRKSRC}/configure

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for ex in srg.daily srg.monthly srg.weekly
	${INSTALL_DATA} ${WRKSRC}/examples/${ex} ${STAGEDIR}${EXAMPLESDIR}
.endfor

.include <bsd.port.mk>
